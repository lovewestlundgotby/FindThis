#include "walker.hpp"

#include "match.hpp"
#include "parser.hpp"
#include "printer.hpp"
#include "types.hpp"

#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/xpressive/detail/core/icase.hpp>
#include <boost/xpressive/regex_constants.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_fwd.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace xp = boost::xpressive;

namespace ft
{
namespace
{
xp::sregex getRegex(const Options& inOptions)
{
  xp::regex_constants::syntax_option_type regexOptions = xp::regex_constants::optimize;
  if (inOptions.ignoreCase)
  {
    regexOptions = regexOptions | xp::regex_constants::icase;
  }
  const xp::sregex re = xp::sregex::compile(inOptions.pattern, regexOptions);
  return re;
}

std::vector<MatchPosition> searchString(const std::string& inString, const xp::sregex& inRe)
{
  std::vector<MatchPosition> matchPositions;
  xp::sregex_iterator regexIterator(inString.begin(), inString.end(), inRe);
  xp::sregex_iterator regexEnd;
  for (; regexIterator != regexEnd; ++regexIterator)
  {
    const xp::smatch& match = *regexIterator;
    s32 a = static_cast<s32>(match[0].first - inString.begin());
    s32 b = static_cast<s32>(match[0].second - inString.begin());
    matchPositions.emplace_back(a, b);
  }

  return matchPositions;
}

}  // namespace

Walker::Walker()
{
}

void Walker::walk(const Options& inOptions)
{
  std::vector<Match> matches;

  const xp::sregex& re = getRegex(inOptions);

  for (const std::string current_dir : inOptions.directory)
  {
    boost::filesystem::recursive_directory_iterator iter(current_dir);
    boost::filesystem::recursive_directory_iterator end;
    for (; iter != end; ++iter)
    {
      const std::string s = iter->path().string();
      if (inOptions.searchFilenames)
      {
        std::vector<MatchPosition> matchPositions = searchString(s, re);
        if (matchPositions.size() > 0)
        {
          matches.emplace_back(s, matchPositions);
        }
      }
      else
      {
        // Open file specified by iter->path()
        // For each line l in file, do regex search with searchStrings(l, re)
      }
    }
  }
  m_printer.print(matches);
}
}  // namespace ft
