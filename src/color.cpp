#include "color.hpp"

#include <iostream>
#include <ostream>
#include <cstdio>
#include <unistd.h>

namespace ft
{
namespace
{
bool printingToTerminal(std::ostream& inStream)
{
  FILE* stream = nullptr;
  if (&inStream == &std::cout)
  {
    stream = stdout;
  }
  else if (&inStream == &std::cerr || &inStream == &std::clog)
  {
    stream = stderr;
  }
  return isatty(fileno(stream));
}

}  // namespace

std::ostream& operator<<(std::ostream& outStream, const Color inColor)
{
  static bool firstUse = true;
  static bool isPrintingToTerminal;
  if (firstUse)
  {
    firstUse = false;
    isPrintingToTerminal = printingToTerminal(outStream);
  }

  if (isPrintingToTerminal)
  {
    return outStream << "\033[" << static_cast<int>(inColor) << "m";
  }
  else
  {
    return outStream;
  }
}
}  // namespace ft
