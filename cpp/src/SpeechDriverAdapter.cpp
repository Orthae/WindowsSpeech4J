#include <iostream>
#include "orthae_com_github_windowsspeech4j_SpeechDriverAdapter.h"
#include "SpeechDriver.h"

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_initialize
	(JNIEnv *env, jobject object) {
  SpeechDriver::getInstance()->initialize(env, object);
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_speak
	(JNIEnv *, jobject, jstring text) {
  SpeechDriver::getInstance()->speak(text);
}

JNIEXPORT jshort JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getVolume
	(JNIEnv *, jobject) {
  return SpeechDriver::getInstance()->getVolume();
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setVolume
	(JNIEnv *, jobject, jshort volume) {
  SpeechDriver::getInstance()->setVolume(volume);
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setRate
	(JNIEnv *, jobject, jshort rate) {
  SpeechDriver::getInstance()->setRate(rate);
}

JNIEXPORT jshort JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getRate
	(JNIEnv *, jobject) {
  return SpeechDriver::getInstance()->getRate();
}

JNIEXPORT jobjectArray JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getVoices
	(JNIEnv *env, jobject) {
  return SpeechDriver::getInstance()->getVoices();
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setVoice
	(JNIEnv *, jobject, jstring voiceHash){
  SpeechDriver::getInstance()->setVoice(voiceHash);
};