#pragma once

#include "ScriptComponent.h"

/**
 * Store for common scripts used throughout the application
 */
class ScriptStore {
public:
  // Uptime counter script that updates the uptime display
  static ScriptComponent getUptimeScript(unsigned long initialMillis) {
    String script = F(
      "function updateUptime() {"
      "  const uptimeElement = document.getElementById('uptime');"
      "  if (!uptimeElement) return;"
      "  let totalMillis = ");
    script += String(initialMillis);
    script += F(";"
      "  try {"
      "    const updateDisplay = () => {"
      "      totalMillis += 1000;"
      "      let seconds = Math.floor(totalMillis / 1000);"
      "      let minutes = Math.floor(seconds / 60);"
      "      let hours = Math.floor(minutes / 60);"
      "      let days = Math.floor(hours / 24);"
      "      seconds %= 60;"
      "      minutes %= 60;"
      "      hours %= 24;"
      "      let display = '';"
      "      if (days > 0) display += days + 'd ';"
      "      if (hours > 0) display += hours + 'h ';"
      "      if (minutes > 0) display += minutes + 'm ';"
      "      display += seconds + 's';"
      "      uptimeElement.innerHTML = display;"
      "    };"
      "    updateDisplay();"
      "    setInterval(updateDisplay, 1000);"
      "  } catch (error) {"
      "    uptimeElement.innerHTML = '<span class=\"text-danger\">Error</span>';"
      "  }"
      "}"
      "setTimeout(updateUptime, 0);"
    );
    return ScriptComponent(script);
  }

  // Memory updater that fetches current memory usage
  static ScriptComponent getMemoryUpdateScript() {
    return ScriptComponent(F(
      "function updateMemory() {"
      "  const memoryElement = document.getElementById('free-memory');"
      "  if (!memoryElement) return;"
      "  try {"
      "    const fetchMemory = () => {"
      "      fetch('/memory')"
      "        .then(response => response.json())"
      "        .then(data => {"
      "          memoryElement.textContent = (data.memory / 1024).toFixed(2) + ' kB';"
      "        })"
      "        .catch(() => {"
      "          memoryElement.innerHTML = '<span class=\"text-danger\">Error</span>';"
      "        });"
      "    };"
      "    fetchMemory();"
      "    setInterval(fetchMemory, 5000);"
      "  } catch (error) {"
      "    memoryElement.innerHTML = '<span class=\"text-danger\">Error</span>';"
      "  }"
      "}"
      "setTimeout(updateMemory, 500);"
    ));
  }

  // Bootstrap version detector
  static ScriptComponent getBootstrapVersionScript() {
    return ScriptComponent(F(
      "document.addEventListener('DOMContentLoaded', function() {"
      "  const versionElement = document.getElementById('bootstrap-version');"
      "  if (!versionElement) return;"
      "  if (typeof bootstrap !== 'undefined') {"
      "    versionElement.textContent = bootstrap.Tooltip.VERSION;"
      "  } else {"
      "    versionElement.textContent = 'Not available';"
      "  }"
      "});"
    ));
  }
};
