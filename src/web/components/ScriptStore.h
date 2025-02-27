#pragma once

#include "ScriptComponent.h"

/**
 * ScriptStore - A factory for commonly used JavaScript components
 * 
 * This class provides static methods that return ScriptComponent instances
 * for reusable JavaScript functionality.
 */
class ScriptStore {
public:
  // Improved uptime display script with smarter formatting
  static ScriptComponent getUptimeScript(unsigned long startTime) {
    String script = F("document.addEventListener('DOMContentLoaded', function() {\n"
                     "  // System boot time in milliseconds\n"
                     "  const bootTimeMs = ");
    script += startTime;
    script += F(";\n"
                "  let initialUptimeMs = bootTimeMs;\n"
                "  \n"
                "  function updateUptime() {\n"
                "    const uptimeElem = document.getElementById('uptime');\n"
                "    if (!uptimeElem) return;\n"
                "    \n"
                "    const uptimeSeconds = Math.floor(initialUptimeMs / 1000) + \n"
                "                         Math.floor((Date.now() - performance.timing.navigationStart) / 1000);\n"
                "    \n"
                "    const days = Math.floor(uptimeSeconds / 86400);\n"
                "    const hours = Math.floor((uptimeSeconds % 86400) / 3600);\n"
                "    const minutes = Math.floor((uptimeSeconds % 3600) / 60);\n"
                "    const seconds = uptimeSeconds % 60;\n"
                "    \n"
                "    // Smart formatting based on elapsed time\n"
                "    let uptimeText = '';\n"
                "    \n"
                "    if (days > 0) {\n"
                "      // Format: Nd HH:MM:SS\n"
                "      uptimeText = days + 'd ' + hours.toString().padStart(2, '0') + ':' +\n"
                "                  minutes.toString().padStart(2, '0') + ':' +\n"
                "                  seconds.toString().padStart(2, '0');\n"
                "    } else if (hours > 0) {\n"
                "      // Format: HH:MM:SS\n"
                "      uptimeText = hours + ':' +\n"
                "                  minutes.toString().padStart(2, '0') + ':' +\n"
                "                  seconds.toString().padStart(2, '0');\n"
                "    } else {\n"
                "      // Format: MM:SS\n"
                "      uptimeText = minutes + ':' +\n"
                "                  seconds.toString().padStart(2, '0');\n"
                "    }\n"
                "    \n"
                "    uptimeElem.textContent = uptimeText;\n"
                "  }\n"
                "  \n"
                "  updateUptime();\n"
                "  setInterval(updateUptime, 1000);\n"
                "});\n");
    return ScriptComponent(script);
  }

  // Memory update script with KB display and 2 decimal places that updates every 3 seconds
  static ScriptComponent getMemoryUpdateScript() {
    // Calculate initial KB with 2 decimal places for first display
    float freeKB = ESP.getFreeHeap() / 1024.0;
    char formattedMem[12];
    sprintf(formattedMem, "%.2f", freeKB);

    String script = F("document.addEventListener('DOMContentLoaded', function() {\n"
                    "  // First try with 'memory' ID, then fall back to 'free-memory' ID\n"
                    "  const memoryElem = document.getElementById('memory') || document.getElementById('free-memory');\n"
                    "  if (!memoryElem) {\n"
                    "    console.error('Memory element not found');\n"
                    "    return;\n"
                    "  }\n\n"
                    "  // Set initial value\n"
                    "  memoryElem.textContent = '");
    script += formattedMem;
    script += F(" KB';\n\n"
                "  function updateMemory() {\n"
                "    fetch('/memory')\n"
                "      .then(response => {\n"
                "        if (!response.ok) throw new Error('Network response failed: ' + response.statusText);\n"
                "        return response.json();\n"
                "      })\n"
                "      .then(data => {\n"
                "        if (data && data.memory) {\n"
                "          // The server already sends the value in KB with proper formatting\n"
                "          memoryElem.textContent = data.memory + ' KB';\n"
                "        } else {\n"
                "          console.error('Invalid memory data format:', data);\n"
                "        }\n"
                "      })\n"
                "      .catch(error => {\n"
                "        console.error('Memory update error:', error);\n"
                "      });\n"
                "  }\n"
                "  \n"
                "  // Update memory immediately and then every 3 seconds\n"
                "  updateMemory();\n"
                "  setInterval(updateMemory, 3000);\n"
                "});\n");
    return ScriptComponent(script);
  }
};
