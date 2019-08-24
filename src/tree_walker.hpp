#ifndef TREE_WALKER_HPP_
#define TREE_WALKER_HPP_

#include "options.hpp"
#include "printer.hpp"

#include <boost/filesystem.hpp>
#include <string>
#include <vector>

namespace walker
{
namespace fs = boost::filesystem;

void walk(printer::Printer inPrinter)
{
  std::vector<fs::path> matches;
  const std::string current_dir = options::opts.directory;
  for (fs::recursive_directory_iterator iter(current_dir), end; iter != end; ++iter)
  {
    matches.push_back(iter->path());
    inPrinter.print(iter->path().string());
  }
}

}  // namespace  walker

#endif  // TREE_WALKER_HPP_
