#pragma once

#include "Component.h"
#include "SVGIcons.h"

/**
 * Card component for Bootstrap cards
 * Updated to use memory-efficient renderTo pattern
 */
class Card : public Component {
public:
  // Constructor using an icon from our Icons namespace
  Card(const Icons::Component& icon, const String& title) 
    : m_iconPtr(&icon), m_title(title), m_content(""), m_useCustomIcon(false) {}
  
  // Constructor using the icon name as a string
  Card(const String& iconName, const String& title)
    : m_iconName(iconName), m_title(title), m_content(""), m_useCustomIcon(true) {}
  
  // Set content for the card
  void setContent(const String& content) {
    m_content = content;
  }

  // Add component directly to content (memory efficient)
  void addComponent(const Component& component) {
    String buffer;
    component.renderTo(buffer);
    m_content += buffer;
  }

  void renderTo(String& buffer) const override {
    buffer += F("<div class='card h-100'><h5 class='card-header'>");
    
    // Render icon based on which constructor was used
    if (m_useCustomIcon) {
      // Use pre-defined icon name
      if (m_iconName == "INFO_ICON") {
        Icons::InfoCircle().renderTo(buffer);
      } else if (m_iconName == "HARDWARE_ICON") {
        Icons::Hardware().renderTo(buffer);
      } else if (m_iconName == "NETWORK_ICON") {
        Icons::Network().renderTo(buffer);
      } else if (m_iconName == "SYSTEM_ICON") {
        Icons::System().renderTo(buffer);
      }
    } else {
      // Use provided icon object
      m_iconPtr->renderTo(buffer);
    }
    
    buffer += F(" ");
    buffer += m_title;
    buffer += F("</h5><div class='card-body'>");
    buffer += m_content;
    buffer += F("</div></div>");
  }

private:
  const Icons::Component* m_iconPtr = nullptr;  // Pointer to the icon component
  String m_iconName;                            // Icon name if using string constructor
  String m_title;                               // Card title
  String m_content;                             // Card content
  bool m_useCustomIcon;                         // Flag for which icon approach to use
};
