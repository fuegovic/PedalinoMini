#pragma once

#include "Component.h"

/**
 * Component that displays connection status with an icon and text
 */
class ConnectionStatus : public Component {
public:
  ConnectionStatus(const String& title, bool isConnected, const String& icon)
    : m_title(title), m_isConnected(isConnected), m_icon(icon) {}
  
  String render() const override {
    String result = F("<div class='row g-1 mb-2'><div class='col-6 d-flex align-items-center'>");
    
    // Icon
    result += F("<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi ");
    result += m_icon;
    result += F(" me-2' viewBox='0 0 16 16'>");
    
    // Add SVG path based on icon type
    if (m_icon == "bi-ethernet") {
      result += F("<path d='M14 13.5v-7a.5.5 0 0 0-.5-.5H12V4.5a.5.5 0 0 0-.5-.5h-1v-.5A.5.5 0 0 0 10 3H6a.5.5 0 0 0-.5.5V4h-1a.5.5 0 0 0-.5.5V6H2.5a.5.5 0 0 0-.5.5v7a.5.5 0 0 0 .5.5h11a.5.5 0 0 0 .5-.5ZM3.75 11h.5a.25.25 0 0 1 .25.25v1.5a.25.25 0 0 1-.25.25h-.5a.25.25 0 0 1-.25-.25v-1.5a.25.25 0 0 1 .25-.25Zm2 0h.5a.25.25 0 0 1 .25.25v1.5a.25.25 0 0 1-.25.25h-.5a.25.25 0 0 1-.25-.25v-1.5a.25.25 0 0 1 .25-.25Zm1.75.25a.25.25 0 0 1 .25-.25h.5a.25.25 0 0 1 .25.25v1.5a.25.25 0 0 1-.25.25h-.5a.25.25 0 0 1-.25-.25v-1.5ZM9.75 11h.5a.25.25 0 0 1 .25.25v1.5a.25.25 0 0 1-.25.25h-.5a.25.25 0 0 1-.25-.25v-1.5a.25.25 0 0 1 .25-.25Zm1.75.25a.25.25 0 0 1 .25-.25h.5a.25.25 0 0 1 .25.25v1.5a.25.25 0 0 1-.25.25h-.5a.25.25 0 0 1-.25-.25v-1.5Z'/>");
    } else if (m_icon == "bi-bluetooth") {
      result += F("<path fill-rule='evenodd' d='m8.543 3.948 1.316 1.316L8.543 6.58V3.948Zm0 8.104 1.316-1.316L8.543 9.42v2.632Zm-1.41-4.043L4.275 5.133l.827-.827L7.377 6.58V1.128l4.137 4.136L8.787 8.01l2.745 2.745-4.136 4.137V9.42l-2.294 2.274-.827-.827L7.133 8.01ZM7.903 16c3.498 0 5.904-1.655 5.904-8.01 0-6.335-2.406-7.99-5.903-7.99C4.407 0 2 1.655 2 8.01 2 14.344 4.407 16 7.904 16Z'/>");
    }
    
    result += F("</svg>");
    result += m_title;
    result += F("</div><div class='col-6 text-end'>");
    
    // Status badge
    if (m_isConnected) {
      result += F("<span class='badge text-bg-success d-inline-flex align-items-center'>");
      result += F("<svg xmlns='http://www.w3.org/2000/svg' width='12' height='12' fill='currentColor' class='bi bi-play-circle-fill me-1' viewBox='0 0 16 16'>");
      result += F("<path d='M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0zM6.79 5.093A.5.5 0 0 0 6 5.5v5a.5.5 0 0 0 .79.407l3.5-2.5a.5.5 0 0 0 0-.814l-3.5-2.5z'/>");
      result += F("</svg>Connected</span>");
    } else {
      result += F("<span class='badge text-bg-danger d-inline-flex align-items-center'>");
      result += F("<svg xmlns='http://www.w3.org/2000/svg' width='12' height='12' fill='currentColor' class='bi bi-stop-circle-fill me-1' viewBox='0 0 16 16'>");
      result += F("<path d='M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0zM6.5 5A1.5 1.5 0 0 0 5 6.5v3A1.5 1.5 0 0 0 6.5 11h3A1.5 1.5 0 0 0 11 9.5v-3A1.5 1.5 0 0 0 9.5 5h-3z'/>");
      result += F("</svg>Disconnected</span>");
    }
    
    result += F("</div></div>");
    return result;
  }

private:
  String m_title;
  bool m_isConnected;
  String m_icon;
};
