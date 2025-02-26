#pragma once

#include "Component.h"

/**
 * A section header component for separating sections in a card
 */
class SectionHeader : public Component {
public:
  SectionHeader(const String& title)
    : m_title(title) {}
  
  String render() const override {
    String result = F("<h6 class='border-bottom pb-2 mt-3 fw-bold'>");
    result += m_title;
    result += F("</h6>");
    return result;
  }

private:
  String m_title;
};
