#ifndef CPP_SPEECHDRIVER_H
#define CPP_SPEECHDRIVER_H

#include <sapi.h>
#include <sphelper.h>
#include <mutex>
#include <vector>
#include "DriverUtility.h"
#include "HandleUtility.h"
#include "Voice.h"

class SpeechDriver {
 private:
  DriverUtility *utility;
  static SpeechDriver *instance;
  static std::mutex mutex;
  JNIEnv *env;
  SpeechDriver();
  ~SpeechDriver();
  ISpVoice *spVoice;
  std::vector<Voice> voices;
 public:
  static SpeechDriver *getInstance();
  void initialize(JNIEnv *env, jobject object);
  void setVolume(unsigned short volume);
  unsigned short getVolume();
  void setRate(short volume);
  short getRate();
  void setVoice(jobject voice);
  jobjectArray getVoices();
  void speak(jstring textToSpeak);
};

#endif