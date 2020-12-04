#include "exit_status.hpp"
#include "parser.hpp"
#include "walker.hpp"

namespace
{
ft::Walker s_walker;
ft::Options s_options;
}  // namespace

int main(const int argc, const char* argv[])
{
  ft::ParseStatus parseStatus = ft::parse(argc, argv, s_options);
  if (parseStatus == ft::ParseStatus::NO_PATTERN || parseStatus == ft::ParseStatus::UNKNOWN_OPTION)
  {
    return ft::ExitStatus::FT_ERROR;
  }

  s_walker.walk(s_options);

  return ft::ExitStatus::FT_SUCCESS;
}
