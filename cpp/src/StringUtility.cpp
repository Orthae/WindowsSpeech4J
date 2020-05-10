#include "StringUtility.h"

StringUtility::StringUtility(JNIEnv *env){
    this->env = env;
}

wchar_t *StringUtility::convertString(jstring string) {
    size_t returnedValue;
    auto source = env->GetStringUTFChars(string, nullptr);
    size_t length = strlen(source)+1;
    wchar_t *destination = new wchar_t[length];
    mbstowcs_s(&returnedValue, destination, length, source, length);
    return destination;
}