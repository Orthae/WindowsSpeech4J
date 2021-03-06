#include "SpeechDriver.h"

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
void SpeechDriver::initialize() {
  HRESULT init = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
  Handle::handleInitialize(init);
  HRESULT inst = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void **)&spVoice);
  Handle::handleCreateInstance(inst);
}

/**
 * Sets volume of the speech
 * @param volume
 * @link https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ee125022(v%3dvs.85)
 */
void SpeechDriver::setVolume(unsigned short volume) {
  HRESULT result = spVoice->SetVolume(volume);
  Handle::handleSetVolume(result);
}

/**
 * Gets volume of the speech
 * @return volume
 * @link https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ee125012(v=vs.85)
 */
unsigned short SpeechDriver::getVolume() {
  unsigned short volume{0};
  HRESULT result = spVoice->GetVolume(&volume);
  Handle::handleGetVolume(result);
  return volume;
}

/**
 * Sets rate of the speech
 * @param rate
 * @link https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ee125019(v=vs.85)
 */
void SpeechDriver::setRate(short rate) {
  HRESULT result = spVoice->SetRate(rate);
  Handle::handleSetRate(result);
}

/**
 * Gets rate of the speech
 * @return rate
 * @link https://docs.microsoft.com/en-us/previous-versions/windows/desktop/ee125008(v=vs.85)
 */
short SpeechDriver::getRate() {
  long rate{0};
  HRESULT result = spVoice->GetRate(&rate);
  Handle::handleGetRate(result);
  return (short)rate;
}



std::vector<Voice> SpeechDriver::getVoices(){
  std::vector<Voice> voices;
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
	voices.emplace_back(Voice(age, gender, languageCode, name, sharedPronunciation, vendor, version, objectToken));
	objectToken->Release();
  }
  return voices;
}

void SpeechDriver::setVoice(size_t hash){
  for(Voice &v : getVoices()) {
    if(v.getHashCode() == hash ){
      spVoice->SetVoice(v.getVoiceToken());
      return;
    }
  }
}


void SpeechDriver::speak(std::wstring textToSpeak) {
  spVoice->Speak(textToSpeak.c_str(), SVSFDefault, nullptr);
}

SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
  CoUninitialize();
}
