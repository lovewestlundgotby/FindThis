#ifndef MATCH_HPP_
#define MATCH_HPP_

#include <ostream>
#include <string>
#include <utility>
#include <vector>

namespace ft
{
using MatchPosition = std::pair<unsigned int, unsigned int>;

class Match
{
public:
  Match(std::string inLine, std::vector<MatchPosition> inPositions)
      : m_line(inLine), m_positions(inPositions)
  {
  }

  ~Match()
  {
  }

  const std::string getLine() const;

  const std::vector<MatchPosition> getMatchPositions() const;

  friend std::ostream& operator<<(std::ostream&, const Match& inMatch);

private:
  std::string m_line;
  std::vector<MatchPosition> m_positions;
};

}  // namespace ft

#endif  // MATCH_HPP_
