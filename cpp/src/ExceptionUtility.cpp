#include "ExceptionUtility.h"

ExceptionUtility::ExceptionUtility(JNIEnv *env) {
    this->env = env;
    this->exceptionClass = env->FindClass(EXCEPTION_CLASS);
    this->exceptionConstructor = env->GetMethodID(exceptionClass, CONSTRUCTOR_METHOD, EXCEPTION_CONSTRUCTOR_SIGNATURE);
}

jthrowable ExceptionUtility::prepareException(int exceptionType, const std::string &message) {
    jstring exceptionMessage = env->NewStringUTF(message.c_str());
    auto trowObj = (jthrowable) env->NewObject(exceptionClass, exceptionConstructor, exceptionType, exceptionMessage);
    return trowObj;
}

void ExceptionUtility::throwException(int exceptionType, const std::string &message) {
    jthrowable exception = prepareException(exceptionType, message);
    env->Throw(exception);
}
