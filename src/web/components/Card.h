#ifndef CARD_H
#define CARD_H

#include "Component.h"
#include "SVGIcons.h"
#include <vector>

/**
 * A Bootstrap card component with title, icon and content
 */
class Card : public Component {
public:
  Card(const SVGIcon& icon, const String& title)
    : m_icon(icon), m_title(title), m_content("") {}
  
  // Add content to the card
  Card& withContent(const String& content) {
    m_content = content;
    return *this;
  }
  
  String render() const override {
    String result = F("<div class='card h-100'><h5 class='card-header'>");
    result += m_icon.render();
    result += F(" ");
    result += m_title;
    result += F("</h5><div class='card-body'>");
    result += m_content;
    result += F("</div></div>");
    return result;
  }

private:
  SVGIcon m_icon;
  String m_title;
  String m_content;
};

#endif // CARD_H
