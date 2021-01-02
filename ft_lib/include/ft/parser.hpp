#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>

namespace ft
{
enum class ParseStatus
{
  SUCCESS,
  DONT_SEARCH,
  NO_PATTERN,
  UNKNOWN_OPTION,
};

class Options
{
public:
  Options()
      : pattern(), directory({"."}), searchFilenames(false), ignoreCase(false), caseSensitive(true)
  {
  }

  std::string pattern;
  std::vector<std::string> directory;
  bool searchFilenames;
  bool ignoreCase;
  bool caseSensitive;
};

ParseStatus parse(const int inArgc, const char* inArgv[], Options& outOptions);

}  // namespace ft

#endif  // PARSER_HPP_
