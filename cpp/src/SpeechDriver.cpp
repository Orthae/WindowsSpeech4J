#include "SpeechDriver.h"

#include <iostream>

SpeechDriver *SpeechDriver::instance{nullptr};
std::mutex SpeechDriver::mutex;

/**
 * Thread safe method for obtaining the singleton instance
 * @return singleton instance of the SpeechDriver class
 */
SpeechDriver *SpeechDriver::getInstance() {
  if (instance == nullptr) {
	std::lock_guard<std::mutex> lock(mutex);
	if (instance == nullptr) {
	  instance = new SpeechDriver();
	}
  }
  return instance;
}

/**
 * Initializes the COM library and creates voice instance
 * @link https://docs.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex
 * @Link https://docs.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance
 */
void SpeechDriver::initialize(JNIEnv *env, jobject object) {
  this->env = env;
  this->utility = new DriverUtility(env, object);
  try {
	HRESULT initResult = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	utility->handleInitialize(initResult);
	HRESULT instanceResult = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void **)&spVoice);
	utility->handleCreateInstance(instanceResult);
  } catch (DriverException &exception) {
	utility->throwException(exception);
  }
}


void SpeechDriver::setVolume(unsigned short volume) {
  HRESULT result = spVoice->SetVolume(volume);
}

unsigned short SpeechDriver::getVolume() {
  unsigned short volume{0};
  HRESULT result = spVoice->GetVolume(&volume);
  return volume;
}

void SpeechDriver::setRate(short rate){
  HRESULT result = spVoice->SetRate(rate);
}

short SpeechDriver::getRate() {
  long rate{0};
  HRESULT result = spVoice->GetRate(&rate);
  return (short)rate;
}



void SpeechDriver::speak(jstring textToSpeak) {
  auto convertedText = utility->convertString(textToSpeak);
  spVoice->Speak(convertedText.c_str(), SVSFDefault, nullptr);
}

SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
  CoUninitialize();
}
