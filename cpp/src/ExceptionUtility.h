#ifndef WINDOWSSPEECH4J_EXCEPTIONUTILITY_H
#define WINDOWSSPEECH4J_EXCEPTIONUTILITY_H

#include <jni.h>
#include <string>
#include "Constants.h"


class ExceptionUtility {
private:
    JNIEnv * env;
    jclass exceptionClass;
    jmethodID exceptionConstructor;
protected:
    jthrowable prepareException(int exceptionType, const std::string &message);
public:
    explicit ExceptionUtility(JNIEnv * env);
    void throwException(int errorType, const std::string &message);
};

#endif