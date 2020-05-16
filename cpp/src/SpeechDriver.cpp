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

jobjectArray SpeechDriver::getVoices(){
  std::vector<Voice> vector;
  ISpObjectTokenCategory *spCategory{nullptr};
  SpGetCategoryFromId(SPCAT_VOICES, &spCategory, FALSE);
  IEnumSpObjectTokens *spEnumTokens{nullptr};
  spCategory->EnumTokens(nullptr, nullptr, &spEnumTokens);
  ISpObjectToken *objectToken;
  while (S_OK == spEnumTokens->Next(1, &objectToken, nullptr)) {
	ISpDataKey *regToken;
	objectToken->OpenKey(L"Attributes", &regToken);
	LPWSTR age;
	regToken->GetStringValue(L"Age", &age);
	LPWSTR gender;
	regToken->GetStringValue(L"Gender", &gender);
	LPWSTR languageCode;
	regToken->GetStringValue(L"Language", &languageCode);
	LPWSTR name;
	regToken->GetStringValue(L"Name", &name);
	LPWSTR sharedPronunciation;
	regToken->GetStringValue(L"SharedPronunciation", &sharedPronunciation);
	LPWSTR vendor;
	regToken->GetStringValue(L"Vendor", &vendor);
	LPWSTR version;
	regToken->GetStringValue(L"Version", &version);
	vector.emplace_back(Voice(age, gender, languageCode, name, sharedPronunciation, vendor, version, objectToken));
	objectToken->Release();
  }
  this->voices = vector;
  return utility->mapVoices(vector);
}

void SpeechDriver::setVoice(jstring hashString){
  size_t hash = utility->getVoiceHashCode(hashString);
  for(Voice &v : voices) {
    if(v.getHashCode() == hash ){
      spVoice->SetVoice(v.getVoiceToken());
      return;
    }
  }
  utility->warn("Voice not found");
}

void SpeechDriver::speak(jstring textToSpeak) {
  auto convertedText = utility->convertString(textToSpeak);
  spVoice->Speak(convertedText.c_str(), SVSFDefault, nullptr);
}

SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
  CoUninitialize();
}
