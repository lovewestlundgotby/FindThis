#include "printer.hpp"

#include "match.hpp"

#include <iostream>
#include <vector>

namespace ft
{
Printer::Printer()
{
}

void Printer::print(const std::vector<Match>& inMatches)
{
  for (const Match& match : inMatches)
  {
    std::cout << match;
  }
  std::cout << std::flush;
}
}  // namespace ft
