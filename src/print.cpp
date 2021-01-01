#include "print.hpp"

#include "match.hpp"

#include <iostream>

namespace ft
{
void print(const walker::SearchResults& inSearchResults)
{
  for (const FileMatch& fm : inSearchResults.fileMatches)
  {
    if (fm.hasMatches())
    {
      std::cout << fm;
    }
  }
  for (const FilenameMatch& fnm : inSearchResults.filenameMatches)
  {
    if (fnm.hasMatches())
    {
      std::cout << fnm;
    }
  }
  std::cout << std::flush;
}
}  // namespace ft
