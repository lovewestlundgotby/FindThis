#include "exit_status.hpp"
#include "parser.hpp"
#include "print.hpp"
#include "walker.hpp"

int main(const int argc, const char* argv[])
{
  ft::Options options;
  const ft::ParseStatus parseStatus = ft::parse(argc, argv, options);
  ft::ExitStatus exitStatus = ft::ExitStatus::FT_SUCCESS;
  switch (parseStatus)
  {
    case ft::ParseStatus::DONT_SEARCH:
    {
      break;
    }
    case ft::ParseStatus::SUCCESS:
    {
      const ft::walker::SearchResults searchResults = ft::walker::walk(options);
      ft::print(searchResults);
      break;
    }
    case ft::ParseStatus::NO_PATTERN:
    case ft::ParseStatus::UNKNOWN_OPTION:
    default:
    {
      exitStatus = ft::ExitStatus::FT_ERROR;
    }
  }

  return exitStatus;
}
