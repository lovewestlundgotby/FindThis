#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_

#include <string>

namespace
{
struct options_t
{
  std::string directory = ".";
};

}  // namespace

namespace options
{
options_t opts;
}  // namespace options

#endif  // OPTIONS_HPP_
