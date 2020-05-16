#ifndef WINDOWSSPEECH4J_SRC_LOGGER_H_
#define WINDOWSSPEECH4J_SRC_LOGGER_H_

#include <jni.h>
#include <string>
#include <mutex>
#include "Constants.h"

class Logger {
 public:
  void error(std::string const &message);
  void warn(std::string const &message);
  static void info(JNIEnv *env, jobject object,std::string const &message);
};

#endif
