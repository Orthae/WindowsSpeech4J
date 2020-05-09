#ifndef WINDOWSSPEECH4J_ADAPTERUTILITY_H
#define WINDOWSSPEECH4J_ADAPTERUTILITY_H
#endif

#include <jni.h>
#include <string>
#include "Constants.h"

class DriverUtility {
private:
    JNIEnv * env;
    jobject object;
    jclass clazz;
public:
    DriverUtility(JNIEnv * env, jobject object);
    void info(std::string const &message);
    void warn(std::string const &message);
    void error(std::string const &message);
    void throwException(char const * type, std::string const &message);
};



