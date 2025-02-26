#pragma once

#include "Component.h"

/**
 * Component for encapsulating JavaScript code
 */
class ScriptComponent : public Component {
public:
  ScriptComponent(const String& script, bool defer = false) 
    : m_script(script), m_defer(defer) {}
  
  String render() const override {
    String result = F("<script");
    if (m_defer) {
      result += F(" defer");
    }
    result += F(">");
    result += m_script;
    result += F("</script>");
    return result;
  }

  // Static helper to minify script (placeholder - actual minification would be more complex)
  static ScriptComponent create(const String& code) {
    return ScriptComponent(code);
  }

private:
  String m_script;
  bool m_defer;
};
