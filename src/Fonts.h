/*
  (c) 2018-2025 alf45star
  https://github.com/alf45tar/PedalinoMini

  This file is part of PedalinoMini.

  You should have received a copy of the GNU General Public License
  along with PedalinoMini. If not, see <http://www.gnu.org/licenses/>.

  Modifications by Fuegovic, 2025.
*/

// Created by http://oleddisplay.squix.ch/
// Edited with the glyphEditor https://rawgit.com/lorol/esp8266-oled-ssd1306/master/resources/glyphEditor.html

const uint8_t DSEG7_Classic_Bold_50[] PROGMEM = {
0x29, // Width: 41
0x37, // Height: 55
0x20, // First char: 32
0x24, // Number of chars: 36
// Jump Table:
0xFF, 0xFF, 0x00, 0x29, // 32
0xFF, 0xFF, 0x00, 0x29, // 33
0xFF, 0xFF, 0x00, 0x29, // 34
0xFF, 0xFF, 0x00, 0x29, // 35
0xFF, 0xFF, 0x00, 0x29, // 36
0xFF, 0xFF, 0x00, 0x29, // 37
0xFF, 0xFF, 0x00, 0x29, // 38
0xFF, 0xFF, 0x00, 0x29, // 39
0xFF, 0xFF, 0x00, 0x29, // 40
0xFF, 0xFF, 0x00, 0x29, // 41
0xFF, 0xFF, 0x00, 0x29, // 42
0xFF, 0xFF, 0x00, 0x29, // 43
0xFF, 0xFF, 0x00, 0x29, // 44
0xFF, 0xFF, 0x00, 0x29, // 45
0x00, 0x00, 0x38, 0x0A, // 46
0xFF, 0xFF, 0x00, 0x29, // 47
0x00, 0x38, 0xFC, 0x29, // 48
0x01, 0x34, 0xFC, 0x29, // 49
0x02, 0x30, 0xF9, 0x29, // 50
0x03, 0x29, 0xFC, 0x29, // 51
0x04, 0x25, 0xFC, 0x29, // 52
0x05, 0x21, 0xFC, 0x29, // 53
0x06, 0x1D, 0xFC, 0x29, // 54
0x07, 0x19, 0xFC, 0x29, // 55
0x08, 0x15, 0xFC, 0x29, // 56
0x09, 0x11, 0xFC, 0x29, // 57
0x0A, 0x0D, 0x37, 0x0A, // 58
0xFF, 0xFF, 0x00, 0x29, // 59
0xFF, 0xFF, 0x00, 0x29, // 60
0xFF, 0xFF, 0x00, 0x29, // 61
0xFF, 0xFF, 0x00, 0x29, // 62
0xFF, 0xFF, 0x00, 0x29, // 63
0xFF, 0xFF, 0x00, 0x29, // 64
0x0A, 0x44, 0xFC, 0x29, // 65
0x0B, 0x40, 0xFC, 0x29, // 66
0x0C, 0x3C, 0xEE, 0x29, // 67
// Font Data:
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, // 46
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0xE0, 0xFD, 0xFF, 0x0F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFB, 0xFF, 0x07, 0xFE, 0xFF, 0x7D, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0x07, 0xFE, 0xFF, 0x7D, 0xE0, 0xFD, 0xFF, 0x0F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 48
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x07, 0xFE, 0xFF, 0x01, 0x00, 0xFC, 0xFF, 0x0F, 0xFF, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x07, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 49
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x40, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x2F, 0xE0, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x77, 0xE0, 0x01, 0x00, 0x60, 0xFF, 0xFF, 0x7B, 0xE0, 0x03, 0x00, 0xF0, 0xFE, 0xFF, 0x7D, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0xF7, 0x00, 0x00, 0x7C, 0xE0, 0xFD, 0xFF, 0x6F, 0x00, 0x00, 0x78, 0xE0, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x70, 0x40, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x20, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, // 50
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xE0, 0x01, 0x00, 0x60, 0x00, 0x00, 0x78, 0xE0, 0x03, 0x00, 0xF0, 0x00, 0x00, 0x7C, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 51
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x6F, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xF7, 0xFE, 0xFF, 0x01, 0x00, 0xFC, 0xFF, 0x6F, 0xFF, 0xFF, 0x03, 0x00, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x07, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 52
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x20, 0xE0, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x70, 0xE0, 0xFD, 0xFF, 0x6F, 0x00, 0x00, 0x78, 0xE0, 0xFB, 0xFF, 0xF7, 0x00, 0x00, 0x7C, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x03, 0x00, 0xF0, 0xFE, 0xFF, 0x7D, 0xE0, 0x01, 0x00, 0x60, 0xFF, 0xFF, 0x7B, 0xE0, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x77, 0x40, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x2F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x0F, // 53
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x03, 0x00, 0xF0, 0xFE, 0xFF, 0x7D, 0xE0, 0x01, 0x00, 0x60, 0xFF, 0xFF, 0x7B, 0xE0, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x77, 0x40, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x2F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x0F, // 54
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0xE0, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0xE0, 0xFD, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0xE0, 0xFB, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFB, 0xFF, 0x07, 0xFE, 0xFF, 0x01, 0xE0, 0xFD, 0xFF, 0x0F, 0xFF, 0xFF, 0x03, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x07, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 55
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 56
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x20, 0xE0, 0xFE, 0xFF, 0x1F, 0x00, 0x00, 0x70, 0xE0, 0xFD, 0xFF, 0x6F, 0x00, 0x00, 0x78, 0xE0, 0xFB, 0xFF, 0xF7, 0x00, 0x00, 0x7C, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0x40, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x2F, 0x80, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0xFF, 0x0F, // 57
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x7C, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x7E, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x7E, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x7C, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x38, 0x00, 0x80, 0x07, // 58
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x1F, 0x40, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x07, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x03, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x01, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x00, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x01, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x03, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x07, 0x40, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, // 65
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0xF7, 0xFF, 0x01, 0xF8, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0x03, 0xFC, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0x07, 0xFE, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0x9F, 0xFF, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0x67, 0xFE, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0xFB, 0xFD, 0xFF, 0x7E, 0xE0, 0xF7, 0xFF, 0xF9, 0xF9, 0xFF, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0xF8, 0x01, 0x00, 0x7E, 0xE0, 0xFB, 0xFF, 0xF7, 0xFE, 0xFF, 0x7D, 0xE0, 0xFD, 0xFF, 0x6F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0x40, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x2F, 0x80, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x1F, 0x00, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, // 66
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x0F, 0x80, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x1F, 0x40, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0x2F, 0xE0, 0xFE, 0xFF, 0x9F, 0xFF, 0xFF, 0x77, 0xE0, 0xFD, 0xFF, 0x0F, 0xFF, 0xFF, 0x7B, 0xE0, 0xFB, 0xFF, 0x07, 0xFE, 0xFF, 0x7D, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, // 67
};