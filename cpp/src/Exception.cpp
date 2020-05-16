#include "Exception.h"

void Exception::throwException(JNIEnv *env, DriverException const &exception) {
  jclass exceptionClass = env->FindClass(Constants::EXCEPTION_CLASS.c_str());
  jmethodID exceptionConstructor =
	  env->GetMethodID(exceptionClass, Constants::CONSTRUCTOR_METHOD.c_str(),
					   Constants::EXCEPTION_CONSTRUCTOR_SIGNATURE.c_str());

  jstring exceptionMessage = env->NewStringUTF(exception.getMessage().c_str());
  auto exceptionJava = (jthrowable) env->NewObject(
	  exceptionClass, exceptionConstructor, exception.getType(), exceptionMessage);

  env->Throw(exceptionJava);
}
