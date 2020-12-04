#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <iostream>
#include <ostream>
#include <string_view>

namespace ft
{
enum LogLevel
{
  DEBUG,
  INFO,
  WARNING,
  WARN = WARNING,
  ERROR,
};

class LogStream
{
public:
  LogStream() = delete;

  explicit LogStream(const char* const inFile, const s32 inLineNumber, LogLevel inLogLevel)
  {
    std::string logLevel{};
    switch (inLogLevel)
    {
      case DEBUG:
        logLevel = "DEBUG";
        break;
      case INFO:
        logLevel = "INFO";
        break;
      case WARNING:
        logLevel = "WARNING";
        break;
      case ERROR:
        logLevel = "ERROR";
        break;
    }
    std::cerr << logLevel << ":" << inFile << ":" << inLineNumber << ": ";
  }

  std::ostream& operator<<(std::string_view inLogMessage)
  {
    return std::cerr << inLogMessage;
  }
};
}  // namespace ft

#define LOG(inLevel) ft::LogStream(__BASE_FILE__, __LINE__, ft::LogLevel::inLevel)

#endif  // LOGGER_HPP_
