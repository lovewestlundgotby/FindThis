#include "walker.hpp"

#include "log.hpp"
#include "macros.hpp"

#include "match.hpp"
#include "parser.hpp"

#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/xpressive/detail/core/icase.hpp>
#include <boost/xpressive/regex_constants.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/xpressive_fwd.hpp>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace xp = boost::xpressive;
namespace fs = boost::filesystem;

namespace ft
{
namespace walker
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

StringMatch searchString(const std::string inString, const xp::sregex& inRe)
{
  std::vector<MatchPosition> matchPositions;
  xp::sregex_iterator regexIterator(inString.begin(), inString.end(), inRe);
  xp::sregex_iterator regexEnd;
  for (; regexIterator != regexEnd; ++regexIterator)
  {
    const xp::smatch& match = *regexIterator;
    int a = static_cast<int>(match[0].first - inString.begin());
    int b = static_cast<int>(match[0].second - inString.begin());
    matchPositions.emplace_back(a, b);
  }
  return {inString, matchPositions};
}

void searchLine(const std::string& inLine,
                const unsigned int inLineNumber,
                const xp::sregex& inRe,
                std::vector<LineMatch>& outLineMatches)
{
  const StringMatch stringMatch = searchString(inLine, inRe);
  if (stringMatch.hasMatches())
  {
    outLineMatches.emplace_back(stringMatch, inLineNumber);
  }
}

FileMatch searchFile(const fs::path& inPath, const xp::sregex& inRe)
{
  std::vector<LineMatch> lineMatches;
  fs::ifstream ifs{inPath, std::ios::in};
  if (!ifs.is_open())
  {
    LOG(ERROR) << "Unable to open file `" << inPath.string() << "`.\n";
    return FileMatch();
  }
  else
  {
    LOG(DEBUG) << "Reading file `" << inPath.string() << "`.\n";
  }
  unsigned int lineNumber = 1;
  for (std::string line; std::getline(ifs, line); ++lineNumber)
  {
    searchLine(line, lineNumber, inRe, lineMatches);
  }
  ifs.close();
  return FileMatch(inPath.string(), lineMatches);
}

}  // namespace

SearchResults walk(const Options& inOptions)
{
  SearchResults searchResults{};

  const xp::sregex& re = getRegex(inOptions);

  for (const std::string& file : inOptions.directory)
  {
    fs::path path = fs::path(file);
    LOG(DEBUG) << path.string() << "\n";
    if (fs::is_directory(path))
    {
      LOG(DEBUG) << "is directory\n";
      fs::recursive_directory_iterator currentFile(file);
      fs::recursive_directory_iterator end;
      for (; currentFile != end; ++currentFile)
      {
        if (inOptions.searchFilenames)
        {
          const std::string& s = currentFile->path().string();
          FilenameMatch fm = searchString(s, re);
          if (fm.hasMatches())
          {
            searchResults.filenameMatches.push_back(fm);
          }
        }
        else if (fs::is_regular_file(currentFile->path()))
        {
          searchResults.fileMatches.push_back(searchFile(currentFile->path(), re));
        }
        else
        {
          // File is a directory, continue.
          continue;
        }
      }
    }
    else if (fs::is_regular_file(path))
    {
      LOG(DEBUG) << "is regular file\n";
      searchResults.fileMatches.push_back(searchFile(path, re));
    }
  }
  return searchResults;
}
}  // namespace walker
}  // namespace ft
