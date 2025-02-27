#pragma once

#include <Arduino.h>

/**
 * Format a file size in bytes into a human-readable string with 
 * appropriate units (KB, MB, etc.)
 */
String formatFileSize(size_t bytes) {
  char buffer[15];
  
  if (bytes >= 1048576) { // >= 1MB
    float mb = bytes / 1048576.0;
    sprintf(buffer, "%.2f MB", mb);
  } else if (bytes >= 1024) { // >= 1KB
    float kb = bytes / 1024.0;
    sprintf(buffer, "%.2f KB", kb);
  } else { // bytes
    sprintf(buffer, "%d bytes", bytes);
  }
  
  return String(buffer);
}

/**
 * Format memory size in bytes to KB with 2 decimal places
 */
String formatMemoryKB(size_t bytes) {
  char buffer[15];
  float kb = bytes / 1024.0;
  sprintf(buffer, "%.2f KB", kb);
  return String(buffer);
}
