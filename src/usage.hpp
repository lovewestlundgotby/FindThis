#ifndef USAGE_HPP_
#define USAGE_HPP_

#include <iostream>

namespace usage
{
const char* HELP =
    "\
FindThis\n\
Love Westlund Gotby\n\
https://github.com/lovewestlundgotby/FindThis\n\n\
FindThis (ft) searches a directory for a pattern.\n\
    ";

const char* USAGE =
    "\
USAGE:\n\
  ft [PATH]\
    ";

void printHelp()
{
  printf("%s\n", HELP);
  printf("%s\n", USAGE);
}

}  // namespace usage

#endif  // USAGE_HPP_
