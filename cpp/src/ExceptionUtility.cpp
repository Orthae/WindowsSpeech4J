#include "ExceptionUtility.h"

ExceptionUtility::ExceptionUtility(JNIEnv *env) {
  this->env = env;
  this->exceptionClass = env->FindClass(Constants::EXCEPTION_CLASS.c_str());
  this->exceptionConstructor =
	  env->GetMethodID(exceptionClass, Constants::CONSTRUCTOR_METHOD.c_str(),
					   Constants::EXCEPTION_CONSTRUCTOR_SIGNATURE.c_str());
}

jthrowable ExceptionUtility::createJavaException(DriverException const &exception) {
  jstring exceptionMessage = env->NewStringUTF(exception.getMessage().c_str());
  auto trowObj = (jthrowable)env->NewObject(
	  exceptionClass, exceptionConstructor, exception.getType(), exceptionMessage);
  return trowObj;
}

void ExceptionUtility::throwException(DriverException const &exception) {
  jthrowable javaException = createJavaException(exception);
  env->Throw(javaException);
}
