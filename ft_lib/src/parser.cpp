#include <ft/parser.hpp>

#include "version.hpp"

#include <boost/program_options.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace ft
{
namespace po = boost::program_options;

namespace
{
constexpr char AUTHOR[]{"Love Westlund Gotby"};
constexpr char URL[]{"https://github.com/lovewestlundgotby/FindThis"};
constexpr char DESCRIPTION[]{
    "FindThis (ft) recursively searches for files or "
    "in files for a regex pattern."};

void printUsage(std::ostream& inOutputStream, const po::options_description& inOptions)
{
  const std::string usage("Usage:\n  ft [OPTIONS] PATTERN [PATH ...]\n");
  inOutputStream << usage << inOptions << std::endl;
}

void doPrintHelp(std::ostream& inOutputStream, const po::options_description& inOptions)
{
  inOutputStream << "ft " << FT_VERSION << "\n"
                 << AUTHOR << "\n"
                 << URL << "\n\n"
                 << DESCRIPTION << "\n\n";
  printUsage(inOutputStream, inOptions);
}

}  // namespace

ParseStatus parse(const int inArgc, const char* inArgv[], Options& outOptions)
{
  // clang-format off
  po::options_description arguments("Positional arguments");
  arguments.add_options()
    ("pattern", po::value<std::string>(&outOptions.pattern)->required(), "Search pattern")
    ("directory",
     po::value<std::vector<std::string> >(&outOptions.directory)->multitoken()->composing(),
     "Search directory");

  po::options_description options("Options");
  options.add_options()
    ("file-name,f",
     po::bool_switch(&outOptions.searchFilenames),
     "Search for filenames matching PATTERN.")
    ("ignore-case,i", po::bool_switch(&outOptions.ignoreCase), "Search case insensitively")
    ("case-sensitive,s", po::bool_switch(&outOptions.caseSensitive), "Search case sensitively");

  po::options_description generic("Generic options");
  bool printHelp{false};
  bool printVersion{false};
  generic.add_options()
    ("help,h", po::bool_switch(&printHelp), "Prints help message.")
    ("version,V", po::bool_switch(&printVersion), "Prints version information.");
  // clang-format on

  po::options_description cmdlineOptions;
  cmdlineOptions.add(arguments).add(options).add(generic);

  po::positional_options_description p;
  p.add("pattern", 1);
  p.add("directory", -1);

  po::command_line_parser parser{inArgc, inArgv};
  const int style =
      (po::command_line_style::allow_short | po::command_line_style::short_allow_adjacent |
       po::command_line_style::short_allow_next | po::command_line_style::allow_dash_for_short |
       po::command_line_style::allow_long | po::command_line_style::long_allow_adjacent |
       po::command_line_style::long_allow_next | po::command_line_style::allow_sticky);
  parser.options(cmdlineOptions).positional(p).allow_unregistered().style(style);
  po::parsed_options parsedOptions = parser.run();
  po::variables_map vm;
  po::store(parsedOptions, vm);

  try
  {
    po::notify(vm);
  }
  catch (po::required_option& e)
  {
    std::cerr << "error: " << e.what() << "\n\n";
    printUsage(std::cerr, cmdlineOptions);
    return ParseStatus::NO_PATTERN;
  }

  if (printHelp)
  {
    doPrintHelp(std::cout, cmdlineOptions);
    return ParseStatus::DONT_SEARCH;
  }

  if (printVersion)
  {
    std::cout << "ft " << FT_VERSION << "\n" << COPYRIGHT << std::endl;
    return ParseStatus::DONT_SEARCH;
  }

  const std::vector<std::string> unknownOptions = po::collect_unrecognized(
      parsedOptions.options, po::collect_unrecognized_mode::exclude_positional);
  if (!unknownOptions.empty())
  {
    std::cout << "Unknown options:\n";
    for (unsigned int i = 0; i < unknownOptions.size(); ++i)
    {
      std::cout << unknownOptions[i];
      if (i < unknownOptions.size() - 1)
      {
        std::cout << "\n";
      }
    }
    std::cout << std::endl;
    return ParseStatus::UNKNOWN_OPTION;
  }

  return ParseStatus::SUCCESS;
}

}  // namespace ft
