#include "log.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace ft
{
namespace
{
std::string logLevelToString(const LogLevel inLogLevel)
{
  std::string logLevel;
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
    default:
      std::abort();
  }
  return logLevel;
}

std::string getOnlyFilename(const char* const inFile)
{
  const char* filenameStart = &inFile[0];
  for (int i = 0; inFile[i] != '\0'; ++i)
  {
    if (inFile[i] == '/' && inFile[i + 1] != '\0')
    {
      filenameStart = &inFile[i + 1];
    }
  }
  return std::string(filenameStart);
}
}  // namespace

LogStream::LogStream(const char* const inFile, const int inLineNumber, const LogLevel inLogLevel)
    : m_stream()
{
  std::string logLevel = logLevelToString(inLogLevel);
  std::string filename = getOnlyFilename(inFile);
  m_stream << logLevel << ":" << filename << ":" << inLineNumber << ": ";
}

LogStream::~LogStream()
{
  std::cout << m_stream.str() << std::flush;
}

}  // namespace ft
