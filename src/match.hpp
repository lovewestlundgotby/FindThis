#ifndef MATCH_HPP_
#define MATCH_HPP_

#include <ostream>
#include <string>
#include <utility>
#include <vector>

namespace ft
{
using MatchPosition = std::pair<unsigned int, unsigned int>;

class StringMatch
{
public:
  StringMatch(const std::string& inLine, const std::vector<MatchPosition>& inPositions)
      : m_line(inLine), m_positions(inPositions)
  {
  }

  friend std::ostream& operator<<(std::ostream& outStream, const StringMatch& inStringMatch);

  bool hasMatches() const
  {
    return !m_positions.empty();
  }

private:
  std::string m_line;
  std::vector<MatchPosition> m_positions;
};

using FilenameMatch = StringMatch;

class LineMatch
{
public:
  LineMatch(const StringMatch& inStringMatch, const unsigned int inLineNumber)
      : m_stringMatch(inStringMatch), m_lineNumber(inLineNumber)
  {
  }

  friend std::ostream& operator<<(std::ostream& outStream, const LineMatch& inLineMatch);

private:
  StringMatch m_stringMatch;
  unsigned int m_lineNumber;
};

class FileMatch
{
public:
  FileMatch(const std::string& inFilename, const std::vector<LineMatch>& inLineMatches)
      : m_filename(inFilename), m_lineMatches(inLineMatches)
  {
  }

  FileMatch() : m_filename(), m_lineMatches()
  {
  }

  bool hasMatches() const
  {
    return !m_lineMatches.empty();
  }

  friend std::ostream& operator<<(std::ostream&, const FileMatch& inMatch);

private:
  std::string m_filename;
  std::vector<LineMatch> m_lineMatches;
};

}  // namespace ft

#endif  // MATCH_HPP_
