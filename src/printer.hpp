#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include <iostream>

namespace printer
{
class Printer
{
public:
  Printer()
  {
  }
  virtual ~Printer()
  {
  }

  void print(const std::string& inMatch)
  {
    std::cout << inMatch << std::endl;
  }
};

}  // namespace printer

#endif  // PRINTER_HPP_
