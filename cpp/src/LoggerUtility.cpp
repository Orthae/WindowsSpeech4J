#include "LoggerUtility.h"

LoggerUtility::LoggerUtility(JNIEnv *env, jobject object) {
  this->env = env;
  this->object = object;
  this->clazz = env->GetObjectClass(object);
}

void LoggerUtility::error(std::string const &message) {
  jmethodID method =
	  env->GetMethodID(clazz,
					   Constants::ADAPTER_LOG_ERROR_NAME.c_str(),
					   Constants::ADAPTER_LOG_ERROR_SIGNATURE.c_str());
  jstring string = env->NewStringUTF(message.c_str());
  env->CallVoidMethod(object, method, string);
}

void LoggerUtility::warn(std::string const &message) {
  jmethodID method =
	  env->GetMethodID(clazz,
					   Constants::ADAPTER_LOG_WARN_NAME.c_str(),
					   Constants::ADAPTER_LOG_WARN_SIGNATURE.c_str());
  jstring string = env->NewStringUTF((message.c_str()));
  env->CallVoidMethod(object, method, string);
}

void LoggerUtility::info(std::string const &message) {
  jmethodID method =
	  env->GetMethodID(clazz,
					   Constants::ADAPTER_LOG_INFO_NAME.c_str(),
					   Constants::ADAPTER_LOG_INFO_SIGNATURE.c_str());
  jstring string = env->NewStringUTF((message.c_str()));
  env->CallVoidMethod(object, method, string);
}