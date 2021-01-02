#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include "match.hpp"
#include "walker.hpp"

#include <iostream>
#include <ostream>
#include <vector>

namespace ft
{
template <typename T>
void print(const std::vector<T>& inVector)
{
  for (const T& t : inVector)
  {
    std::cout << t;
  }
  std::cout << std::flush;
}

void print(const walker::SearchResults& inSearchResults);
}  // namespace ft

#endif  // PRINTER_HPP_
