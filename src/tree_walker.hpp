#ifndef TREE_WALKER_HPP_
#define TREE_WALKER_HPP_

#include "options.hpp"
#include "printer.hpp"

#include <filesystem>
#include <string>
#include <vector>

namespace walker
{
namespace fs = std::filesystem;

void walk(printer::Printer inPrinter)
{
  std::vector<fs::directory_entry> matches;
  const std::string current_dir = options::opts.directory;
  for (const fs::directory_entry& p : fs::recursive_directory_iterator(current_dir))
  {
    matches.push_back(p);
    inPrinter.print(p.path().string());
  }
}

}  // namespace  walker

#endif  // TREE_WALKER_HPP_
