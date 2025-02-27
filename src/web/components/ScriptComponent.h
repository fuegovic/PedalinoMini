#pragma once

#include "Component.h"

/**
 * ScriptComponent - A component for encapsulating JavaScript code
 * 
 * This component renders JavaScript code blocks with proper script tags
 * and implements the memory-efficient rendering pattern.
 */
class ScriptComponent : public Component {
private:
  String m_code;
  bool m_defer;
  
public:
  // Constructor with script code and optional defer flag
  ScriptComponent(const String& code, bool defer = false) 
    : m_code(code), m_defer(defer) {}
  
  // Memory-efficient rendering to an existing buffer
  void renderTo(String& buffer) const override {
    buffer += F("<script");
    if (m_defer) {
      buffer += F(" defer");
    }
    buffer += F(">\n");
    buffer += m_code;
    buffer += F("\n</script>\n");
  }
};
