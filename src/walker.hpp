#ifndef WALKER_HPP_
#define WALKER_HPP_

#include "parser.hpp"
#include "printer.hpp"

namespace ft
{
class Walker
{
public:
  Walker();

  void walk(const Options& inOptions);

private:
  Printer m_printer;
};

}  // namespace ft

#endif  // TREE_WALKER_HPP_
