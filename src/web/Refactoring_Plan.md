# Pedalino Web Interface Refactoring Plan

## Current Progress (February 26, 2025)

### Completed:
- ✅ Created base Component interface with virtual render() method
- ✅ Implemented StatusItem component as first building block
- ✅ Created ScriptComponent for encapsulating JavaScript
- ✅ Extracted SVG icons into dedicated SVGIcons.h file
- ✅ Implemented Card component with content management
- ✅ Added SectionHeader component 
- ✅ Created ConnectionStatus component
- ✅ Created ScriptStore for centralized script management
- ✅ Started integrating components into root page

### In Progress:
- 🟡 WebChunker utility - initial implementation needed
- 🟡 Memory optimization - addressing increased consumption

### Observations:

1. **Memory Impact**: Initial component implementation has increased memory usage (from ~65KB to ~55KB free memory). This needs addressing through:
   - Consider using renderTo(buffer) pattern instead of returning String objects
   - Reduce object creation/destruction cycles
   - Explore fixed-size buffers for components with known size requirements

2. **Integration Strategy**: The gradual approach is working well. We've started with the product info card in the home page and can continue replacing sections incrementally.

3. **Component Reusability**: Already seeing benefits from StatusItem component reuse across multiple cards.

### Next Steps:
1. Implement WebChunker utility to better manage memory chunking
2. Continue refining memory usage with heap monitoring
3. Complete home page refactoring with all components
4. Implement NavBar component for consistent navigation
5. Begin implementation of input components for forms

### Memory Optimization Priorities:
1. Modify Component interface to use buffer references instead of String returns
2. Create component pooling for frequently used components
3. Use PROGMEM more aggressively for static content

---

## Goal
Create a modular, maintainable web interface by refactoring the monolithic WebConfigAsync.h file into a component-based architecture that separates concerns while maintaining memory efficiency.

## Files Affected
- Primary: WebConfigAsync.h
- New structure under web

## Project Structure

```
/src
  /web
    /controllers      # Request handlers by feature
      HomeController.h        # Handles root/home page requests
      ActionsController.h     # Handles bank/actions page
      PedalsController.h      # Handles pedal config
      ConfigController.h      # General config handlers
      SystemController.h      # System operations (update, etc)
      
    /components       # Reusable UI components
      Component.h             # Base component interface
      StatusItem.h            # Key-value pair component
      Card.h                  # Card container component
      NavBar.h                # Navigation component
      Alert.h                 # Alert messages
      InputComponents.h       # Form controls
      SVGIcons.h              # Extracted SVG icons
      
    /layouts          # Page templates/layouts
      PageLayout.h            # Base page layout
      ContentLayout.h         # Content area layout
      
    /middleware       # Auth handling
      AuthMiddleware.h        # Authentication logic
      
    /utils            # Web helper functions
      WebChunker.h            # Memory chunking helper
      HTMLHelpers.h           # HTML generation utilities
      ColorUtils.h            # Color conversion helpers
```

## Implementation Phases

### Phase 1: Foundation Setup (6-8 hours)
1. Create base Component interface
2. Implement WebChunker for memory management
3. Extract SVG icons into separate file
4. Create basic StatusItem component 

### Phase 2: Basic Component Implementation (8-10 hours)
1. Implement Card component
2. Create Alert component
3. Implement NavBar component
4. Build base page layout
5. Convert HomePage to use components

### Phase 3: First Page Migration (10-12 hours)
1. Implement HomePage controller
2. Refactor get_root_page() to use component structure
3. Test thoroughly for memory issues
4. Add AuthMiddleware integration

### Phase 4: Additional Core Components (10-12 hours)
1. Create form input components
2. Build specialized components for actions, pedals
3. Extract JavaScript functions
4. Implement color utils

### Phase 5: Additional Pages (25-30 hours)
1. Refactor Actions page
2. Refactor Pedals page
3. Refactor Controls page
4. Refactor remaining configuration pages

### Phase 6: Final Integration (8-10 hours)
1. Update main WebConfigAsync.h to use controllers
2. Implement route registration system
3. Complete documentation
4. Final testing

## Implementation Details

### Component Base Class
```cpp
#pragma once
#include <Arduino.h>

class Component {
public:
  // Render HTML representation of component
  virtual String render() = 0;
  virtual ~Component() {}
};
```

### Memory Management Strategy
- Implement WebChunker class to handle memory-efficient page delivery
- Keep existing chunking mechanism but wrap in a cleaner interface
- Allow progressive rendering of components

### Testing Strategy
1. Implement components one by one
2. Test each component individually
3. Monitor memory usage with ESP.getFreeHeap()
4. Test incremental page loading with large pages
5. Verify browser compatibility

## Timeline & Milestones

1. **Week 1 (10-15 hours)**: 
   - Complete Phases 1 & 2
   - Implement basic component architecture
   - See StatusItem working

2. **Week 2-3 (15-20 hours)**:
   - Complete Phase 3
   - Migrate home page
   - Implementation of card and layout components

3. **Week 4-6 (25-30 hours)**:
   - Complete Phases 4 & 5
   - Migrate complex pages

4. **Week 7 (8-10 hours)**:
   - Complete Phase 6
   - Integration, testing and optimization

## Getting Started: First Implementation Task - DONE ✓

Implemented the StatusItem component as the first building block:
```cpp
#pragma once
#include "Component.h"

class StatusItem : public Component {
private:
  String label;
  String value;
  
public:
  StatusItem(const String& label, const String& value)
    : label(label), value(value) {}
  
  String render() override {
    String html;
    html += F("<div class='row g-1 mb-2'><div class='col-6'>");
    html += label;
    html += F("</div><div class='col-6 text-end'>");
    html += value;
    html += F("</div></div>");
    return html;
  }
};
```

## Next Steps After StatusItem

1. Create the WebChunker utility class
2. Extract SVG icons to a dedicated file
3. Implement the Card component

Let me know if you'd like to focus on any specific aspect of this plan first!