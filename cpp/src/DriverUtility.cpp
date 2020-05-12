#include "DriverUtility.h"

DriverUtility::DriverUtility(JNIEnv *env, jobject object) {
  this->exceptionUtility = new ExceptionUtility(env);
  this->stringUtility = new StringUtility(env);
  this->loggerUtility = new LoggerUtility(env, object);
}
DriverUtility::~DriverUtility() {
  delete this->exceptionUtility;
  delete this->stringUtility;
}

void DriverUtility::throwException(DriverException const &exception) {
  exceptionUtility->throwException(exception);
}

std::wstring DriverUtility::convertString(jstring javaString) {
  return stringUtility->convertString(javaString);
}

void DriverUtility::error(std::string const &message) {
  loggerUtility->error(message);
}

void DriverUtility::warn(std::string const &message) {
  loggerUtility->warn(message);
}

void DriverUtility::info(std::string const &message) {
  loggerUtility->info(message);
}