#include <iostream>
#include "orthae_com_github_windowsspeech4j_SpeechDriverAdapter.h"
#include "SpeechDriver.h"
#include "Exception.h"

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_build
	(JNIEnv *env, jobject object) {
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_initialize
	(JNIEnv *env, jobject object) {
  try {
	SpeechDriver::getInstance()->initialize();
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
}

JNIEXPORT jshort JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getVolume
	(JNIEnv *env, jobject) {
  try {
	return SpeechDriver::getInstance()->getVolume();
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
  return 0;
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setVolume
	(JNIEnv *env, jobject, jshort volume) {
  try {
	SpeechDriver::getInstance()->setVolume(volume);
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
}

//JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_speak
//	(JNIEnv *, jobject, jstring text) {
////  SpeechDriver::getInstance()->speak(text);
//}
//

//
//JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setRate
//	(JNIEnv *, jobject, jshort rate) {
////  SpeechDriver::getInstance()->setRate(rate);
//}
//
////JNIEXPORT jshort JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getRate
////	(JNIEnv *, jobject) {
//////  return SpeechDriver::getInstance()->getRate();
////}
//
//JNIEXPORT jobjectArray JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getVoices
//	(JNIEnv *env, jobject) {
////  return SpeechDriver::getInstance()->getVoices();
//}
//
//JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setVoice
//	(JNIEnv *, jobject, jstring voiceHash) {
////  SpeechDriver::getInstance()->setVoice(voiceHash);
//};