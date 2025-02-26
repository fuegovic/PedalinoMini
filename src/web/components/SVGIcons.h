#pragma once

#include "Component.h"

/**
 * SVG icon component that renders an icon with customizable size
 */
class SVGIcon : public Component {
public:
  SVGIcon(const String& icon, int width = 32, int height = 32) 
    : m_icon(icon), m_width(width), m_height(height) {}
  
  String render() const override {
    String result = F("<svg xmlns='http://www.w3.org/2000/svg' width='");
    result += String(m_width);
    result += F("' height='");
    result += String(m_height);
    result += F("' fill='currentColor' class='bi ");
    result += m_icon;
    result += F("' viewBox='0 0 16 16'>");
    
    // Get the path data based on icon name
    if (m_icon == "bi-info-circle") {
      result += INFO_ICON_PATH;
    } else if (m_icon == "bi-cpu") {
      result += HARDWARE_ICON_PATH;
    } else if (m_icon == "bi-wifi") {
      result += NETWORK_ICON_PATH;
    } else if (m_icon == "bi-gear") {
      result += SYSTEM_ICON_PATH;
    }
    
    result += F("</svg>");
    return result;
  }

private:
  String m_icon;
  int m_width;
  int m_height;

  // SVG path definitions
  static const char INFO_ICON_PATH[] PROGMEM;
  static const char HARDWARE_ICON_PATH[] PROGMEM;
  static const char NETWORK_ICON_PATH[] PROGMEM;
  static const char SYSTEM_ICON_PATH[] PROGMEM;
};

// Define the SVG paths
const char SVGIcon::INFO_ICON_PATH[] PROGMEM = 
  "<path d='M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16z'/>"
  "<path d='m8.93 6.588-2.29.287-.082.38.45.083c.294.07.352.176.288.469l-.738 3.468c-.194.897.105 1.319.808 1.319.545 0 1.178-.252 1.465-.598l.088-.416c-.2.176-.492.246-.686.246-.275 0-.375-.193-.304-.533L8.93 6.588zM9 4.5a1 1 0 1 1-2 0 1 1 0 0 1 2 0z'/>";

const char SVGIcon::HARDWARE_ICON_PATH[] PROGMEM = 
  "<path d='M5 0a.5.5 0 0 1 .5.5V2h1V.5a.5.5 0 0 1 1 0V2h1V.5a.5.5 0 0 1 1 0V2h1V.5a.5.5 0 0 1 1 0V2A2.5 2.5 0 0 1 14 4.5h1.5a.5.5 0 0 1 0 1H14v1h1.5a.5.5 0 0 1 0 1H14v1h1.5a.5.5 0 0 1 0 1H14v1h1.5a.5.5 0 0 1 0 1H14a2.5 2.5 0 0 1-2.5 2.5v1.5a.5.5 0 0 1-1 0V14h-1v1.5a.5.5 0 0 1-1 0V14h-1v1.5a.5.5 0 0 1-1 0V14h-1v1.5a.5.5 0 0 1-1 0V14A2.5 2.5 0 0 1 2 11.5H.5a.5.5 0 0 1 0-1H2v-1H.5a.5.5 0 0 1 0-1H2v-1H.5a.5.5 0 0 1 0-1H2v-1H.5a.5.5 0 0 1 0-1H2A2.5 2.5 0 0 1 4.5 2V.5A.5.5 0 0 1 5 0zm-.5 3A1.5 1.5 0 0 0 3 4.5v7A1.5 1.5 0 0 0 4.5 13h7a1.5 1.5 0 0 0 1.5-1.5v-7A1.5 1.5 0 0 0 11.5 3h-7zM5 6.5A1.5 1.5 0 0 1 6.5 5h3A1.5 1.5 0 0 1 11 6.5v3A1.5 1.5 0 0 1 9.5 11h-3A1.5 1.5 0 0 1 5 9.5v-3z'/>";

const char SVGIcon::NETWORK_ICON_PATH[] PROGMEM = 
  "<path d='M15.384 6.115a.485.485 0 0 0-.047-.736A12.444 12.444 0 0 0 8 3c-2.82 0-5.432.952-7.337 2.38a.485.485 0 0 0-.047.735.518.518 0 0 0 .668.05A11.448 11.448 0 0 1 8 4c2.597 0 4.99.883 6.766 2.166a.518.518 0 0 0 .668-.05'/>"
  "<path d='M13.229 8.271a.482.482 0 0 0-.063-.745A9.455 9.455 0 0 0 8 6c-2.086 0-4.02.666-5.166 1.526a.48.48 0 0 0-.063.745.525.525 0 0 0 .652.065A8.46 8.46 0 0 1 8 7a8.46 8.46 0 0 1 4.576 1.336c.206.132.48.108.653-.065zm-2.183 2.183c.226-.226.185-.605-.1-.75A6.473 6.473 0 0 0 8 9c-1.06 0-2.062.254-2.946.704-.285.145-.326.524-.1.75l.015.015c.16.16.407.19.611.09A5.478 5.478 0 0 1 8 10c.868 0 1.69.201 2.42.56.203.1.45.07.61-.091l.016-.015zM9.06 12.44c.196-.196.198-.52-.04-.66A1.99 1.99 0 0 0 8 11.5a1.99 1.99 0 0 0-1.02.28c-.238.14-.236.464-.04.66l.706.706a.5.5 0 0 0 .707 0l.707-.707z'/>";

const char SVGIcon::SYSTEM_ICON_PATH[] PROGMEM = 
  "<path d='M8 4.754a3.246 3.246 0 1 0 0 6.492 3.246 3.246 0 0 0 0-6.492zM5.754 8a2.246 2.246 0 1 1 4.492 0 2.246 2.246 0 0 1-4.492 0z'/>"
  "<path d='M9.796 1.343c-.527-1.79-3.065-1.79-3.592 0l-.094.319a.873.873 0 0 1-1.255.52l-.292-.16c-1.64-.892-3.433.902-2.54 2.541l.159.292a.873.873 0 0 1-.52 1.255l-.319.094c-1.79.527-1.79 3.065 0 3.592l.319.094a.873.873 0 0 1 .52 1.255l-.16.292c-.892 1.64.901 3.434 2.541 2.54l.292-.159a.873.873 0 0 1 1.255.52l.094.319c.527 1.79 3.065 1.79 3.592 0l.094-.319a.873.873 0 0 1 1.255-.52l.292.16c1.64.893 3.434-.902 2.54-2.541l-.159-.292a.873.873 0 0 1 .52-1.255l.319-.094c1.79-.527 1.79-3.065 0-3.592l-.319-.094a.873.873 0 0 1-.52-1.255l.16-.292c.893-1.64-.902-3.433-2.541-2.54l-.292.159a.873.873 0 0 1-1.255-.52l-.094-.319zm-2.633.283c.246-.835 1.428-.835 1.674 0l.094.319a1.873 1.873 0 0 0 2.693 1.115l.291-.16c.764-.415 1.6.42 1.184 1.185l-.159.292a1.873 1.873 0 0 0 1.116 2.692l.318.094c.835.246.835 1.428 0 1.674l-.319.094a1.873 1.873 0 0 0-1.115 2.693l.16.291c.415.764-.42 1.6-1.185 1.184l-.291-.159a1.873 1.873 0 0 0-2.693 1.116l-.094.318c-.246.835-1.428.835-1.674 0l-.094-.319a1.873 1.873 0 0 0-2.692-1.115l-.292.16c-.764.415-1.6-.42-1.184-1.185l.159-.291A1.873 1.873 0 0 0 1.945 8.93l-.319-.094c-.835-.246-.835-1.428 0-1.674l.319-.094A1.873 1.873 0 0 0 3.06 4.377l-.16-.292c-.415-.764.42-1.6 1.185-1.184l.292.159a1.873 1.873 0 0 0 2.692-1.115l.094-.319z'/>";

/**
 * Convenience functions to create icons with standard settings
 */
namespace Icons {
  // Standard icons with default size
  static SVGIcon InfoCircle() { return SVGIcon("bi-info-circle"); }
  static SVGIcon Hardware() { return SVGIcon("bi-cpu"); }
  static SVGIcon Network() { return SVGIcon("bi-wifi"); }
  static SVGIcon System() { return SVGIcon("bi-gear"); }
  
  // Custom-sized icons
  static SVGIcon InfoCircle(int size) { return SVGIcon("bi-info-circle", size, size); }
  static SVGIcon Hardware(int size) { return SVGIcon("bi-cpu", size, size); }
  static SVGIcon Network(int size) { return SVGIcon("bi-wifi", size, size); }
  static SVGIcon System(int size) { return SVGIcon("bi-gear", size, size); }
}