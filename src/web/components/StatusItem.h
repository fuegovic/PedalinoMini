#pragma once
#include "Component.h"

/**
 * StatusItem component - Displays a label/value row
 * 
 * This component renders a two-column row with label on the left
 * and value on the right, commonly used in status displays.
 * Updated to use the memory-efficient renderTo pattern.
 */
class StatusItem : public Component {
public:
  StatusItem(const String& label, const String& value)
    : m_label(label), m_value(value) {}
  
  void renderTo(String& buffer) const override {
    buffer += F("<div class='row g-1 mb-2'><div class='col-6'>");
    buffer += m_label;
    buffer += F("</div><div class='col-6 text-end'>");
    buffer += m_value;
    buffer += F("</div></div>");
  }

private:
  String m_label;
  String m_value;
};
