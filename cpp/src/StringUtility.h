#ifndef WINDOWSSPEECH4J_STRINGUTILITY_H
#define WINDOWSSPEECH4J_STRINGUTILITY_H

#include <jni.h>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>

class StringUtility {
private:
    JNIEnv * env;
public:
    StringUtility(JNIEnv * env);
    wchar_t * convertString(jstring string);
};


#endif