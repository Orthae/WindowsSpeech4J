#include <iostream>
#include "Logger.h"

//void Logger::error(std::string const &message) {
//  jmethodID method =
//	  env->GetMethodID(clazz,
//					   Constants::ADAPTER_LOG_ERROR_NAME.c_str(),
//					   Constants::ADAPTER_LOG_ERROR_SIGNATURE.c_str());
//  jstring string = env->NewStringUTF(message.c_str());
//  env->CallVoidMethod(object, method, string);
//}
//
//void Logger::warn(std::string const &message) {
//  jmethodID method =
//	  env->GetMethodID(clazz,
//					   Constants::ADAPTER_LOG_WARN_NAME.c_str(),
//					   Constants::ADAPTER_LOG_WARN_SIGNATURE.c_str());
//  jstring string = env->NewStringUTF((message.c_str()));
//  env->CallVoidMethod(objecet, method, string);
//}

void Logger::info(JNIEnv *env, jobject object,std::string const &message) {
//  std::cout << "Inside1 message is: " << message << std::endl;
//  jmethodID method =
//	  env->GetMethodID(clazz,
//					   Constants::ADAPTER_LOG_INFO_NAME.c_str(),
//					   Constants::ADAPTER_LOG_INFO_SIGNATURE.c_str());
//  std::cout << "Inside2" << std::endl;
//  jstring string = env->NewStringUTF((message.c_str()));
//  std::cout << "Inside3" << std::endl;
//  env->CallVoidMethod(object, method, string);
//  std::cout << "Inside4" << std::endl;
}