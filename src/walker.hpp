#ifndef WALKER_HPP_
#define WALKER_HPP_

#include "parser.hpp"

#include "match.hpp"

namespace ft
{
namespace walker
{
struct SearchResults
{
  std::vector<FileMatch> fileMatches;
  std::vector<FilenameMatch> filenameMatches;
};

SearchResults walk(const Options& inOptions);

}  // namespace walker
}  // namespace ft

#endif  // TREE_WALKER_HPP_
