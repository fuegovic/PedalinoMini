#pragma once

#include <Arduino.h>

/**
 * Utility to handle chunked page rendering
 */
class WebChunker {
public:
  WebChunker(unsigned int maxAllocation = 8192) : 
    m_maxAllocation(maxAllocation),
    m_page(""),
    m_skipped(0),
    m_pageCompleted(false) {}
  
  // Append content to the page buffer
  void append(const String& content) {
    m_page += content;
  }
  
  // Get and clear current page buffer 
  String getAndClear() {
    String result = m_page;
    m_page = "";
    return result;
  }
  
  // Get current page buffer without clearing
  const String& get() const {
    return m_page;
  }
  
  // Clear page buffer
  void clear() {
    m_page = "";
  }
  
  // Trim page to fit within the specified chunk size
  bool trimToChunk(unsigned int start, unsigned int length, bool lastCall = false) {
    static unsigned int skipped = 0;
    unsigned int fullPageLength;
    
    const unsigned int saved = m_page.length();
    
    if (saved > m_maxAllocation) {
      Serial.printf("Memory fragmentation warning: webpage memory allocation %d bytes greater than %d bytes reserved (requested %d bytes).\n%s\n", 
                    saved, m_maxAllocation, length, m_page.c_str());
    }
    
    if (m_pageCompleted) {
      skipped = 0;
      m_pageCompleted = false;
    }
    
    fullPageLength = skipped + saved;
    
    // Start is after last addition
    if (start > (fullPageLength - 1)) {
      m_page = "";
      skipped += saved;
      return false;
    }
    
    // Start is in the last addition
    if (start > (fullPageLength - saved)) {
      m_page.remove(0, start - (fullPageLength - saved));
      skipped += start - (fullPageLength - saved);
    }
    
    // Finish reached
    if (fullPageLength >= (start + length) || lastCall) {
      if (m_page.length() > length) {
        m_page.remove(length);
      }
      skipped = 0;
      m_pageCompleted = true;
      return true;
    }
    
    return false;
  }

private:
  unsigned int m_maxAllocation;
  String m_page;
  unsigned int m_skipped;
  bool m_pageCompleted;
};
