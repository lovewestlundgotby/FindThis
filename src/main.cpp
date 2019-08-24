#include "exit_status.hpp"
#include "options.hpp"
#include "parser.hpp"
#include "printer.hpp"
#include "tree_walker.hpp"

namespace
{
printer::Printer s_printer;
}  // namespace

int main(const int argc, const char* argv[])
{
  int return_value;
  return_value = parser::parse(argc, argv);
  if (return_value == EXIT_ERROR)
  {
    return return_value;
  }
  else if (return_value == parser::EXIT_HELP)
  {
    return EXIT_FOUND_MATCH;
  }

  walker::walk(s_printer);

  return return_value;
}
