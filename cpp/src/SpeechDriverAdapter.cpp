#include "orthae_com_github_windowsspeech4j_SpeechDriverAdapter.h"
#include "SpeechDriver.h"

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_initialize
(JNIEnv * env, jobject object){
    SpeechDriver::getInstance()->initialize(env, object);
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_speak
(JNIEnv *, jobject, jstring text){
    SpeechDriver::getInstance()->speak(text);
}