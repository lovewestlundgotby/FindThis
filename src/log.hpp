#ifndef LOG_HPP_
#define LOG_HPP_

#include "macros.hpp"

#include <sstream>
#include <cstdlib>

#if !defined(NDEBUG)
#define ENABLE_LOGGING
#endif

namespace ft
{
enum LogLevel
{
  DEBUG,
  INFO,
  WARNING,
  ERROR,
};

class LogStream
{
public:
  LogStream(const char* const inFile, const int inLineNumber, const LogLevel inLogLevel);

  ~LogStream();

  template <typename T>
  LogStream& operator<<(const T& inLogMessage)
  {
    m_stream << inLogMessage;
    return *this;
  }

private:
  std::ostringstream m_stream;
};

class NullLogStream
{
public:
  NullLogStream(const char* const inFile, const int inLineNumber, const LogLevel inLogLevel)
  {
    IGNORE_UNUSED_PARAM(inFile);
    IGNORE_UNUSED_PARAM(inLineNumber);
    IGNORE_UNUSED_PARAM(inLogLevel);
  };

  template <typename T>
  NullLogStream& operator<<(const T& inLogMessage)
  {
    IGNORE_UNUSED_PARAM(inLogMessage);
    return *this;
  }
};

#if defined(ENABLE_LOGGING)
#define LOGGER ft::LogStream
#else
#define LOGGER ft::NullLogStream
#endif

#define LOG(inLevel) LOGGER(__BASE_FILE__, __LINE__, ft::LogLevel::inLevel)

}  // namespace ft
#endif  // LOG_HPP_
