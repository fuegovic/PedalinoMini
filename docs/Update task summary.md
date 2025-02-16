Here's a detailed task summary including the GPIO capability changes:

# Task: Migrate to Single GPIO Per Pedal Architecture

## Overview
Convert the current dual GPIO per pedal architecture to a single GPIO per pedal design, optimizing analog-capable GPIOs for maximum functionality.

## Notes
> - board = esp32doit-devkit-v1 
> - bump support for 20 LEDS
> - update the PIN_ASSIGNMENT docs when the job is done

## Key Architecture Changes

### 1. GPIO Assignment Strategy
```cpp
// New GPIO pin assignments optimized for ESP32 capabilities
struct gpio_capability {
    uint8_t gpio;      // GPIO number
    bool    analog;    // True if GPIO can handle analog input
    bool    input;     // True if GPIO can be used as input
};

const gpio_capability GPIO_CAP[] = {
    // Analog-capable GPIOs (ADC1) - Assign to first pedals
    {GPIO_NUM_36, true,  true},  // ADC1_CH0 - Pedal 1
    {GPIO_NUM_39, true,  true},  // ADC1_CH3 - Pedal 2
    {GPIO_NUM_34, true,  true},  // ADC1_CH6 - Pedal 3
    {GPIO_NUM_35, true,  true},  // ADC1_CH7 - Pedal 4
    {GPIO_NUM_32, true,  true},  // ADC1_CH4 - Pedal 5
    {GPIO_NUM_33, true,  true},  // ADC1_CH5 - Pedal 6

    // Digital-only GPIOs - Assign to remaining pedals
    {GPIO_NUM_25, false, true},  // Pedal 7
    {GPIO_NUM_26, false, true},  // Pedal 8
    // ...etc
};
```

> Note: Available GPIOs are:
```
Analog:
    GPIO_NUM_36,  // Pedal 1
    GPIO_NUM_39,  // Pedal 2
    GPIO_NUM_34,  // Pedal 3
    GPIO_NUM_35,  // Pedal 4
    GPIO_NUM_32,  // Pedal 5 
    GPIO_NUM_33,  // Pedal 6

Digital:
    GPIO_NUM_25,  // Pedal 7
    GPIO_NUM_26,  // Pedal 8
    GPIO_NUM_27,  // Pedal 9
    GPIO_NUM_14,  // Pedal 10
    GPIO_NUM_13,  // Pedal 11
    GPIO_NUM_17,  // Pedal 12
    GPIO_NUM_16,  // Pedal 13
    GPIO_NUM_15,  // Pedal 14
    GPIO_NUM_0    // Pedal 15 (shared with BOOT)
```

### 2. Pedal Mode Mapping
- Analog-capable GPIOs (1-6):
  - All analog modes (analog, analog pad)
  - All digital modes (momentary, latch)
  - Advanced modes (jog wheel, ultrasonic)

- Digital-only GPIOs (7-15):
  - Digital modes only (momentary, latch)

### 3. Remove Dual-GPIO Modes
Delete or comment out:
```cpp
#define PED_MOMENTARY2        6   // Remove
#define PED_MOMENTARY3        7   // Remove
#define PED_LATCH2           8   // Remove
#define PED_ANALOG_MOMENTARY  11  // Remove  
#define PED_ANALOG_LATCH     12  // Remove
#define PED_ANALOG_PAD_MOMENTARY 14 // Remove
```

## Implementation Steps

1. Update GPIO Configuration
- Create new GPIO capability structure
- Map pedals to GPIOs based on capabilities
- Update pin initialization code

2. Simplify Pedal Modes
- Remove all dual GPIO modes
- Update mode enums and constants
- Clean up related configuration code

3. Update Controller Logic
- Modify pedal reading logic for single GPIO
- Update analog/digital input handling
- Clean up action handling code

4. Update Web Interface
- Remove dual GPIO mode options
- Update pedal configuration forms
- Modify help text and documentation

5. Update Configuration Storage
- Update EEPROM/flash storage format
- Add migration code for existing configurations

## Files to Modify

1. Config.h:
- Add GPIO capability definitions
- Update pin assignments
- Remove dual GPIO constants

2. Controller.h:
- Update pedal reading logic
- Modify input processing

3. Pedalino.h:
- Update pedal mode definitions
- Remove dual GPIO support code

4. WebConfigAsync.h:
- Update configuration interface
- Remove dual GPIO options

## Testing Requirements

1. Verify all pedal modes work:
- Digital modes on all GPIOs
- Analog modes on analog-capable GPIOs
- Edge cases and combinations

2. Test hardware configurations:
- Different pedal types
- Various GPIO assignments
- Analog calibration

3. Verify configuration:
- Saving/loading settings
- Web interface updates
- Migration of existing configs

## Benefits
- Simpler architecture
- More efficient GPIO usage
- Clearer hardware setup
- Reduced code complexity
- More intuitive configuration

## Note on Breaking Changes
This is a breaking change - existing configurations using dual GPIO modes will need to be migrated. Consider adding a configuration migration utility.