#pragma once

#include "Component.h"
#include "SVGIcons.h"

/**
 * Component that displays connection status with an icon and text
 * Updated to use memory-efficient renderTo pattern
 */
class ConnectionStatus : public Component {
private:
  String m_title;
  bool m_isConnected;
  String m_iconHtml;
  
public:
  ConnectionStatus(const String& title, bool isConnected, const String& iconHtml)
    : m_title(title), m_isConnected(isConnected), m_iconHtml(iconHtml) {}
  
  void renderTo(String& buffer) const override {
    buffer += F("<div class='row g-1 mb-2'><div class='col-6 d-flex align-items-center'>");
    
    // Icon (already includes the SVG)
    buffer += m_iconHtml;
    buffer += m_title;
    buffer += F("</div><div class='col-6 text-end'>");
    
    // Status badge
    if (m_isConnected) {
      buffer += F("<span class='badge text-bg-success d-inline-flex align-items-center'>");
      Icons::PlayCircleFill().renderTo(buffer);
      buffer += F("Connected</span>");
    } else {
      buffer += F("<span class='badge text-bg-danger d-inline-flex align-items-center'>");
      Icons::StopCircleFill().renderTo(buffer);
      buffer += F("Disconnected</span>");
    }
    
    buffer += F("</div></div>");
  }
};
