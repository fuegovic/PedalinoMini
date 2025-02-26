#pragma once

#include <Arduino.h>

/**
 * Base Component class for all UI components
 */
class Component {
public:
  virtual String render() const = 0;
  virtual ~Component() = default;
};
