# Profile Switching Feature Update

## Overview
The PedalinoMini now supports cycling through three distinct profiles (A, B, and C) using dedicated profile switching actions.

## Using Profile Actions
Two actions are available for profile switching:
- **Profile+**: Cycles forward through profiles (A → B → C → A)
- **Profile-**: Cycles backward through profiles (A → C → B → A)

## Profile Order
The profiles are arranged in a circular sequence:
- **Profile A** (0)
- **Profile B** (1)
- **Profile C** (2)

## How to Use
1. Configure a pedal with either the `Profile+` or `Profile-` action
2. Press the pedal to cycle through profiles
3. Current profile will be displayed on screen
4. Your settings are automatically saved when switching profiles

## Important Notes
- The current bank settings are automatically saved before switching profiles
- Profile changes are prevented while a previous profile is still loading
- The system will always default to Profile A if an invalid profile is detected

## Display Feedback
When switching profiles, you'll see:
- The profile letter (A, B, or C)
- The profile number (0, 1, or 2)
- A brief confirmation message

## Tips
- Use Profile+ for forward cycling (A→B→C)
- Use Profile- for reverse cycling (A→C→B)
- You can assign both actions to different pedals for quick access in either direction

# PedalinoMini Pin Assignments

## 15-Pedal Configuration

### Physical Pin Layout
Pedal|Digital Pin|Analog Pin|Capabilities|Notes
-----|-----------|----------|------------|-----
1|GPIO 0|GPIO 36|Expression|ADC1_CH0 (works with WiFi)
2|GPIO 0|GPIO 39|Expression|ADC1_CH3 (works with WiFi)
3|GPIO 0|GPIO 34|Expression|ADC1_CH6 (works with WiFi)
4|GPIO 0|GPIO 35|Expression|ADC1_CH7 (works with WiFi)
5|GPIO 0|GPIO 32|Expression|ADC1_CH4 (works with WiFi)
6|GPIO 0|GPIO 33|Expression|ADC1_CH5 (works with WiFi)
7|GPIO 25|GPIO 0|Switch|Digital only
8|GPIO 26|GPIO 0|Switch|Digital only
9|GPIO 27|GPIO 0|Switch|Digital only
10|GPIO 14|GPIO 0|Switch|Digital only
11|GPIO 13|GPIO 0|Switch|Digital only
12|GPIO 17|GPIO 0|Switch|Digital only
13|GPIO 16|GPIO 0|Switch|Digital only
14|GPIO 15|GPIO 0|Switch|Digital only (shared with MIDI)
15|GPIO 0|GPIO 0|Switch|Digital only (shared with BOOT)

### Important Limitations
1. ADC2 pins (GPIO 25, 26, 27, 14, 12, 13, 15, 16, 17, 18) cannot be used as analog inputs when WiFi is active
2. Input-only pins (GPIO 34, 35, 36, 39) cannot be used as digital outputs
3. Each pedal in WebUI can be configured independently as:
   - Digital input (momentary or latch)
   - Analog input (expression pedal)
   - Part of a dual-pedal setup (using both digital and analog capabilities)
4. You can mix and match pedal types based on your needs:
   - Use ADC1 pins for analog when WiFi is needed
   - Use any GPIO for digital inputs
   - Use input-only pins primarily for expression pedals

### Reserved System Pins
Function|GPIO Pin|Notes
--------|--------|-----
GPIO 18|USB MIDI IN|Reserved for USB MIDI communication
GPIO 19|USB MIDI OUT|Reserved for USB MIDI communication
Factory Default|GPIO 0|Boot button
DIN MIDI IN|GPIO 15|Shared with pedal 13
DIN MIDI OUT|GPIO 4|
FastLED Data|GPIO 5|For WS2812B LED strip

### Pedal Configuration Guide

#### Digital Switch Pedals (7-15)
- Best for momentary or latching footswitches
- Full GPIO capabilities
- Perfect for traditional footswitches
- No analog capabilities
- Use internal pull-up resistors
- Connect switch between GPIO and GND

#### Analog Expression Pedals (1-6)
- Input-only pins with ADC1
- Perfect for expression pedals
- Works with WiFi enabled
- No pull-up/down resistors
- Cannot be used as outputs
- Best analog performance
- Use with 3.3V reference

### Important Notes

1. ADC1 (Pedals 1-6)
   - Works with WiFi enabled
   - Best analog performance
   - 12-bit resolution
   - Voltage range: 0-3.3V

2. Digital Inputs
   - Internal pull-up resistors available
   - Connect switch between GPIO and GND
   - Debouncing handled in software

3. Expression Pedals
   - Use pedals 1-6 for best performance
   - Connect to input-only pins (36, 39, 34, 35)
   - No external pull-up needed
   - Always works with WiFi

4. Shared Pins
   - GPIO 15: Pedal 14 / MIDI IN
   - GPIO 0: Pedal 15 / BOOT button
   - Plan usage accordingly

5. Best Practices
   - Use pedals 7-15 for footswitches
   - Use pedals 1-6 for expression pedals

## Hardware Connection Notes

### Buttons
- Connect one side of each button to its corresponding GPIO pin
- Connect the other side of each button to GND
- Internal pull-up resistors will be enabled in software

### Potentiometer
- Connect the middle pin (wiper) to GPIO (GPIO with Analog support, see table above)
- Connect one outer pin to 3.3V
- Connect the other outer pin to GND
- No external pull-up/pull-down resistors needed

### Important Notes
1. All GPIO pins are safe for boot - no special precautions needed
2. GPIO 36 is shared between the potentiometer and battery voltage reading
3. Configure buttons in WebUI as:
   - Mode: "Momentary 1" or "Latch 1"
   - Enable desired press modes (Single/Double/Long)
4. Configure potentiometer in WebUI as:
   - Mode: "Analog"
   - Adjust response curve and calibration as needed
5. Expansion slots 14-16 use input-only GPIOs, perfect for analog readings or digital inputs
6. Expansion slot 13 (GPIO 33) can be used as either digital input/output or analog input

### Hardware Connection Guide

#### For Footswitches (Pedals 7-15)
```
GPIO ----[SWITCH]---- GND
```

#### For Expression Pedals (Pedals 1-6)
```
3.3V ----[POT HIGH]
         [POT WIPER]---- GPIO
GND  ----[POT LOW]