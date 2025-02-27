#pragma once
#include <Arduino.h>

/**
 * Base Component interface for UI components
 * 
 * This interface defines the methods that UI components must implement.
 * It provides both memory-efficient renderTo and legacy render methods
 * to allow for a smooth transition to more memory-efficient patterns.
 */
class Component {
public:
  // Primary method: Render directly to an existing buffer (memory efficient)
  virtual void renderTo(String& buffer) const = 0;
  
  // Legacy method for transition period: returns a new string
  virtual String render() const {
    String result;
    renderTo(result);
    return result;
  }
  
  virtual ~Component() {}
};
