#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "exit_status.hpp"
#include "options.hpp"
#include "usage.hpp"

#include <boost/program_options.hpp>
#include <string>
#include <vector>

namespace
{
}  // namespace

namespace parser
{
namespace po = boost::program_options;

enum
{
  EXIT_HELP = 10,
  HELP_NO_PATTERN = 11,
  HELP_UNKNOWN_OPTION = 12,
};

int parse(const int inArgc, const char* inArgv[])
{
  po::options_description desc("Allowed options");
  desc.add_options()("help,h", "produce help message")(
      "directory", po::value<std::string>(), "Search directory");

  po::positional_options_description p;
  p.add("directory", -1);

  po::variables_map vm;
  po::store(po::command_line_parser(inArgc, inArgv).options(desc).positional(p).run(), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    usage::printHelp();
    return EXIT_HELP;
  }

  if (vm.count("directory"))
  {
    options::opts.directory = vm["directory"].as<std::string>();
  }

  return EXIT_NO_MATCH;
}

}  // namespace parser

#endif  // PARSER_HPP_
