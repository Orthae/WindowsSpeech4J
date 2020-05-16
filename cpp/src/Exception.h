#ifndef WINDOWSSPEECH4J_EXCEPTIONUTILITY_H
#define WINDOWSSPEECH4J_EXCEPTIONUTILITY_H

#include <jni.h>
#include <string>
#include "DriverException.h"
#include "Constants.h"

class Exception {
 protected:
  static jthrowable createJavaException(JNIEnv *env, DriverException const &exception);
 public:
  static void throwException(JNIEnv *env, DriverException const &exception);
};

#endif