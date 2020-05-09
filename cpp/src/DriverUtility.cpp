#include <iostream>
#include "DriverUtility.h"

DriverUtility::DriverUtility(JNIEnv * env, jobject object) {
    this->env = env;
    this->object = object;
    this->clazz = env->GetObjectClass(object);
}

void DriverUtility::error(std::string const &message) {
    jmethodID method = env->GetMethodID(clazz, ADAPTER_LOG_ERROR_NAME, ADAPTER_LOG_ERROR_SIGNATURE);
    jstring string = env->NewStringUTF(message.c_str());
    env->CallVoidMethod(object, method, string);
}

void DriverUtility::warn(std::string const &message) {
    jmethodID method = env->GetMethodID(clazz, ADAPTER_LOG_WARN_NAME, ADAPTER_LOG_WARN_SIGNATURE);
    jstring string = env->NewStringUTF((message.c_str()));
    env->CallVoidMethod(object, method, string);
}

void DriverUtility::info(std::string const &message) {
    jmethodID method = env->GetMethodID(clazz, ADAPTER_LOG_INFO_NAME, ADAPTER_LOG_INFO_SIGNATURE);
    jstring string = env->NewStringUTF((message.c_str()));
    env->CallVoidMethod(object, method, string);
}

void DriverUtility::throwException(char const * type, const std::string &message) {
    jclass newExcCls = env->FindClass(type);
    env->ThrowNew(newExcCls, message.c_str());
}