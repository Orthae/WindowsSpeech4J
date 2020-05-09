#include "orthae_com_github_windowsspeech4j_SpeechDriverAdapter.h"
#include "SpeechDriver.h"
#include <iostream>

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_initialize(JNIEnv * env, jobject object){
    SpeechDriver::getInstance()->initialize();
}