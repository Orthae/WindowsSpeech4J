#ifndef CPP_SPEECHDRIVER_H
#define CPP_SPEECHDRIVER_H

#include <sapi.h>
#include <sphelper.h>
#include <mutex>
#include "DriverUtility.h"

class SpeechDriver {
 private:
  DriverUtility *utility;
  static SpeechDriver *instance;
  static std::mutex mutex;
  JNIEnv *env;
  SpeechDriver();
  ~SpeechDriver();
  ISpVoice *spVoice;
 protected:
  void handleInitialize(HRESULT result);
  void handleCreateInstance(HRESULT result);
 public:
  static SpeechDriver *getInstance();
  void setVolume(unsigned short volume);
  unsigned short getVolume();
  void setRate(short volume);
  short getRate();
  void initialize(JNIEnv *env, jobject object);
  void speak(jstring textToSpeak);
};

#endif