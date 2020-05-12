#include "DriverException.h"

DriverException::DriverException(int const type, std::string const &message) {
  this->type = type;
  this->message = message;
}

int DriverException::getType() const {
  return type;
}

std::string DriverException::getMessage() const {
  return message;
}
