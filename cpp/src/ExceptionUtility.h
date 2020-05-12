#ifndef WINDOWSSPEECH4J_EXCEPTIONUTILITY_H
#define WINDOWSSPEECH4J_EXCEPTIONUTILITY_H

#include <jni.h>
#include <string>
#include "DriverException.h"
#include "Constants.h"

class ExceptionUtility {
 private:
  JNIEnv *env;
  jclass exceptionClass;
  jmethodID exceptionConstructor;
 protected:
  jthrowable createJavaException(DriverException const &exception);
 public:
  explicit ExceptionUtility(JNIEnv *env);
  void throwException(DriverException const &exception);
};

#endif