#ifndef WINDOWSSPEECH4J_STRINGUTILITY_H
#define WINDOWSSPEECH4J_STRINGUTILITY_H

#include <jni.h>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "Voice.h"

class TypeUtility {
 private:
  JNIEnv *env;
 public:
  TypeUtility(JNIEnv *env);
  std::wstring convertString(jstring javaString);
  jobjectArray mapVoices(std::vector<Voice> voices);
  Voice mapVoice(jobject jObject);
};

#endif