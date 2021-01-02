#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <ostream>

namespace ft
{
enum class Color : int
{
  RESET = 0,

  // Type settings.
  BOLD = 1,
  NO_BOLD = 21,
  UNDERLINE = 4,
  NO_UNDERLINE = 24,

  // Foreground.
  FG_BLACK = 30,
  FG_RED = 31,
  FG_GREEN = 32,
  FG_YELLOW = 33,
  FG_BLUE = 34,
  FG_MAGENTA = 35,
  FG_CYAN = 36,
  FG_WHITE = 37,
  FG_RESET = 39,
  // Background.
  BG_BLACK = 40,
  BG_RED = 41,
  BG_GREEN = 42,
  BG_BLUE = 44,
  BG_MAGENTA = 45,
  BG_CYAN = 46,
  BG_WHITE = 47,
  BG_RESET = 49,
  // Foreground bright.
  FG_BRIGHT_BLACK = 90,
  FG_BRIGHT_RED = 91,
  FG_BRIGHT_GREEN = 92,
  FG_BRIGHT_YELLOW = 93,
  FG_BRIGHT_BLUE = 94,
  FG_BRIGHT_MAGENTA = 95,
  FG_BRIGHT_CYAN = 96,
  FG_BRIGHT_WHITE = 97,
  // Background bright.
  BG_BRIGHT_BLACK = 100,
  BG_BRIGHT_RED = 101,
  BG_BRIGHT_GREEN = 102,
  BG_BRIGHT_YELLOW = 103,
  BG_BRIGHT_BLUE = 104,
  BG_BRIGHT_MAGENTA = 105,
  BG_BRIGHT_CYAN = 106,
  BG_BRIGHT_WHITE = 107,
};

std::ostream& operator<<(std::ostream& outStream, const Color inColor);

}  // namespace ft

#endif  // COLOR_HPP_
