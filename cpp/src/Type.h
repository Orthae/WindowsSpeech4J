#ifndef WINDOWSSPEECH4J_STRINGUTILITY_H
#define WINDOWSSPEECH4J_STRINGUTILITY_H

#include <jni.h>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "Voice.h"

class Type {
 public:
  static std::wstring convertString(JNIEnv *env, jstring javaString);
  static jobjectArray mapVoices(JNIEnv *env, std::vector<Voice> voices);
  static size_t getVoiceHashCode(JNIEnv *env, jstring hashString);
};

#endif