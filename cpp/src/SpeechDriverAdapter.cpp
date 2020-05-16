#include <iostream>
#include "orthae_com_github_windowsspeech4j_SpeechDriverAdapter.h"
#include "SpeechDriver.h"
#include "Exception.h"
#include "Type.h"

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

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setRate
	(JNIEnv *env, jobject, jshort rate) {
  try {
	SpeechDriver::getInstance()->setRate(rate);
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
}

JNIEXPORT jshort JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getRate
	(JNIEnv *env, jobject) {
  try {
	return SpeechDriver::getInstance()->getRate();
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
  return 0;
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_setVoice
	(JNIEnv *env, jobject, jstring stringHash) {
  try {
	size_t hash = Type::getVoiceHashCode(env, stringHash);
	SpeechDriver::getInstance()->setVoice(hash);
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }

}

JNIEXPORT jobjectArray JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_getVoices
	(JNIEnv *env, jobject) {
  try {
	std::vector voices = SpeechDriver::getInstance()->getVoices();
	return Type::mapVoices(env, voices);
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
  return nullptr;
}

JNIEXPORT void JNICALL Java_orthae_com_github_windowsspeech4j_SpeechDriverAdapter_speak
	(JNIEnv *env, jobject, jstring jText) {
  try {
    std::wstring text = Type::convertString(env, jText);
	SpeechDriver::getInstance()->speak(text);
  } catch (DriverException &exception) {
	Exception::throwException(env, exception);
  }
}