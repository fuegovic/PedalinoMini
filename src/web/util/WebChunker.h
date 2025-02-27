#pragma once
#include <Arduino.h>

/**
 * WebChunker - Memory-efficient web content management
 *
 * This class encapsulates the logic for chunking web content to avoid memory
 * fragmentation on ESP32. It handles buffer management and trimming for
 * progressive content delivery.
 */
class WebChunker {
private:
  String& m_page;                // Reference to the global page string
  unsigned int& m_skipped;       // Reference to skipped count
  bool& m_fullPageCompleted;     // Reference to completion flag
  unsigned int m_memoryAllocation; // Maximum memory allocation for the page
  
public:
  // Constructor takes references to existing memory management variables
  WebChunker(String& pageRef, unsigned int& skippedRef, bool& completedRef, unsigned int memoryAllocation = 8192)
    : m_page(pageRef), m_skipped(skippedRef), m_fullPageCompleted(completedRef), m_memoryAllocation(memoryAllocation) {}
  
  // Write to the buffer with memory monitoring
  void write(const String& content) {
    m_page += content;
  }
  
  // Write flash strings directly (more memory efficient)
  void write(const __FlashStringHelper* content) {
    m_page += content;
  }
  
  // Process chunk with similar logic to trim_page
  bool process(unsigned int start, unsigned int len, bool lastcall = false) {
    const unsigned int saved = m_page.length();
    unsigned int fullPageLength;

    if (saved > m_memoryAllocation) {
      DPRINT("Memory fragmentation warning: webpage memory allocation %d bytes greater than %d bytes reserved (requested %d bytes).\n", 
             saved, m_memoryAllocation, len);
    }

    if (m_fullPageCompleted) {
      m_skipped = 0;
      m_fullPageCompleted = false;
    }

    fullPageLength = m_skipped + saved;

    // Start is after last addition
    if (start > (fullPageLength - 1)) {
      m_page = "";
      m_skipped += saved;
      return false;
    }

    // Start is in the last addition
    if (start > (fullPageLength - saved)) {
      m_page.remove(0, start - (fullPageLength - saved));
      m_skipped += start - (fullPageLength - saved);
    }

    // Finish reached
    if (fullPageLength >= (start + len) || lastcall) {
      if (len > 1) m_page.remove(len - 1);
      m_skipped = 0;
      m_fullPageCompleted = true;
      return true;
    }

    return false;
  }
  
  // Clear the buffer
  void clear() {
    m_page = "";
  }

  // Get current length
  size_t length() const {
    return m_page.length();
  }

  // Write a component directly to the buffer
  template<typename T>
  void writeComponent(const T& component) {
    component.renderTo(m_page);
  }
};
