#include "match.hpp"

#include "color.hpp"

#include <ostream>
#include <string_view>
#include <vector>

namespace ft
{
std::ostream& operator<<(std::ostream& outStream, const StringMatch& inStringMatch)
{
  const std::string_view line = inStringMatch.m_line;
  const std::vector<MatchPosition>& mps = inStringMatch.m_positions;

  const MatchPosition& firstMP = mps.front();
  const MatchPosition& lastMP = mps.back();
  outStream << line.substr(0, firstMP.first);
  outStream << Color::FG_BRIGHT_RED << Color::BOLD << Color::UNDERLINE
            << line.substr(firstMP.first, firstMP.second - firstMP.first) << Color::RESET;

  if (mps.size() > 1)
  {
    for (unsigned int mpIdx = 1; mpIdx < mps.size(); ++mpIdx)
    {
      const MatchPosition& mp = mps[mpIdx];
      const MatchPosition& previousMP = mps[mpIdx - 1];
      outStream << line.substr(previousMP.second, mp.first - previousMP.second);
      outStream << Color::FG_BRIGHT_RED << line.substr(mp.first, mp.second - mp.first)
                << Color::FG_RESET;
    }
  }
  outStream << line.substr(lastMP.second) << "\n";

  return outStream;
}

std::ostream& operator<<(std::ostream& outStream, const LineMatch& inLineMatch)
{
  outStream << Color::FG_BRIGHT_YELLOW << inLineMatch.m_lineNumber << Color::RESET << ":";
  outStream << inLineMatch.m_stringMatch;
  return outStream;
}

std::ostream& operator<<(std::ostream& outStream, const FileMatch& inMatch)
{
  if (!inMatch.m_filename.empty())
  {
    outStream << Color::FG_BRIGHT_MAGENTA << inMatch.m_filename << Color::RESET << "\n";
  }
  for (const LineMatch& lineMatch : inMatch.m_lineMatches)
  {
    outStream << lineMatch;
  }
  return outStream;
}
}  // namespace ft
