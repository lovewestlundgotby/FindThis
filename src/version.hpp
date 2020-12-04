#ifndef VERSION_HPP_
#define VERSION_HPP_

#include "types.hpp"

#include <string>

namespace ft
{
constexpr s32 MAJOR_VERSION = 0;
constexpr s32 MINOR_VERSION = 1;

std::string getVersion()
{
  return std::to_string(MAJOR_VERSION) + std::string(".") + std::to_string(MINOR_VERSION);
}

std::string getFtVersion()
{
  return std::string("ft ") + getVersion();
}
}  // namespace ft

#endif  // VERSION_HPP_
