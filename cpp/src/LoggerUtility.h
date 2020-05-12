#ifndef WINDOWSSPEECH4J_SRC_LOGGERUTILITY_H_
#define WINDOWSSPEECH4J_SRC_LOGGERUTILITY_H_

#include <jni.h>
#include <string>
#include "Constants.h"

class LoggerUtility {
 private:
  JNIEnv * env;
  jclass clazz;
  jobject object;
 public:
  LoggerUtility(JNIEnv * env, jobject object);
  void error(std::string const &message);
  void warn(std::string const &message);
  void info(std::string const &message);
};

#endif
