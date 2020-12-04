#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include "match.hpp"

#include <vector>

namespace ft
{
class Printer
{
public:
  Printer();

  void print(const std::vector<Match>& inMatches);
};

}  // namespace ft

#endif  // PRINTER_HPP_
