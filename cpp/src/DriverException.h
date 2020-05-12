#ifndef WINDOWSSPEECH4J_SRC_DRIVEREXCEPTION_H_
#define WINDOWSSPEECH4J_SRC_DRIVEREXCEPTION_H_

#include <exception>
#include <string>

class DriverException : public std::exception {
 private:
  int type;
  std::string message;
 public:
	DriverException(int const type, std::string const &message);
	int getType() const;
	std::string getMessage() const ;
};

#endif
