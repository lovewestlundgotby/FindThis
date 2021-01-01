#include "match.hpp"

#include "color.hpp"

#include <ostream>
#include <vector>

namespace ft
{
const std::string Match::getLine() const
{
  return m_line;
}

const std::vector<MatchPosition> Match::getMatchPositions() const
{
  return m_positions;
}

std::ostream& operator<<(std::ostream& outStream, const Match& inMatch)
{
  const std::string& line = inMatch.getLine();
  const std::vector<MatchPosition>& mps = inMatch.getMatchPositions();

  const MatchPosition& firstMP = mps.front();
  const MatchPosition& lastMP = mps.back();
  outStream << line.substr(0, firstMP.first);
  outStream << Color::FG_BRIGHT_RED << line.substr(firstMP.first, firstMP.second - firstMP.first)
            << Color::FG_RESET;

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
}  // namespace ft
