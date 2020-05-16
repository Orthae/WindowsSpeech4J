#ifndef CPP_SPEECHDRIVER_H
#define CPP_SPEECHDRIVER_H

#include <sapi.h>
#include <sphelper.h>
#include <mutex>
#include <vector>
#include "Handle.h"
#include "Voice.h"

class SpeechDriver {
 private:
  static SpeechDriver *instance;
  static std::mutex mutex;
  SpeechDriver();
  ~SpeechDriver();
  ISpVoice *spVoice;
 public:
  void initialize();
  static SpeechDriver *getInstance();
  void setVolume(unsigned short volume);
  unsigned short getVolume();
  void setRate(short volume);
  short getRate();
  void setVoice(size_t hash);
  std::vector<Voice> getVoices();
  void speak(std::wstring textToSpeak);
};

#endif