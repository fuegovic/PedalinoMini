#pragma once

#include "Component.h"

/**
 * SectionHeader - A component for section headers in Bootstrap
 * 
 * This component renders a styled h6 heading suitable for section dividers
 */
class SectionHeader : public Component {
private:
  String m_title;
  
public:
  SectionHeader(const String& title) : m_title(title) {}
  
  void renderTo(String& buffer) const override {
    buffer += F("<h6 class='border-bottom pb-2 mt-3 fw-bold'>");
    buffer += m_title;
    buffer += F("</h6>");
  }
};
