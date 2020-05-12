#ifndef WINDOWSSPEECH4J_ADAPTERUTILITY_H
#define WINDOWSSPEECH4J_ADAPTERUTILITY_H

#include <jni.h>
#include <string>
#include "Constants.h"
#include "ExceptionUtility.h"
#include "StringUtility.h"
#include "LoggerUtility.h"

class DriverUtility {
 private:
  ExceptionUtility *exceptionUtility;
  StringUtility *stringUtility;
  LoggerUtility *loggerUtility;
 public:
  DriverUtility(JNIEnv *env, jobject object);
  ~DriverUtility();
  void info(std::string const &message);
  void warn(std::string const &message);
  void error(std::string const &message);
  void throwException(int exceptionType, const std::string &message);
  std::wstring convertString(jstring javaString);
};

#endif