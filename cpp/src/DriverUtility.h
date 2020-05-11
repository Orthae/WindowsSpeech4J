#ifndef WINDOWSSPEECH4J_ADAPTERUTILITY_H
#define WINDOWSSPEECH4J_ADAPTERUTILITY_H

#include <jni.h>
#include <string>
#include "ExceptionUtility.h"
#include "Constants.h"
#include "StringUtility.h"

class DriverUtility {
 private:
  ExceptionUtility *exceptionUtility;
  StringUtility *stringUtility;
  JNIEnv *env;
  jobject object;
  jclass clazz;
 public:
  DriverUtility(JNIEnv *env, jobject object);
  ~DriverUtility();
  void info(std::string const &message);
  void warn(std::string const &message);
  void error(std::string const &message);
  void throwException(int exceptionType, const std::string &message);
  wchar_t *convertString(jstring string);
};

#endif