#include "DriverUtility.h"

DriverUtility::DriverUtility(JNIEnv * env, jobject object) {
    this->exceptionUtility = new ExceptionUtility(env);
    this->stringUtility = new StringUtility(env);
    this->env = env;
    this->object = object;
    this->clazz = env->GetObjectClass(object);
}
DriverUtility::~DriverUtility(){
    delete this->exceptionUtility;
    delete this->stringUtility;
}

void DriverUtility::throwException(int exceptionType, std::string const &message) {
    exceptionUtility->throwException(exceptionType, message);
}

wchar_t * DriverUtility::convertString(jstring string){
    return stringUtility->convertString(string);
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