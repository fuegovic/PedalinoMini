#pragma once

#include "Component.h"

/**
 * A status item component for displaying label-value pairs
 */
class StatusItem : public Component {
public:
  StatusItem(const String& label, const String& value)
    : m_label(label), m_value(value) {}
  
  String render() const override {
    String result = F("<div class='row g-1 mb-2'><div class='col-6'>");
    result += m_label;
    result += F("</div><div class='col-6 text-end'>");
    result += m_value;
    result += F("</div></div>");
    return result;
  }

private:
  String m_label;
  String m_value;
};
