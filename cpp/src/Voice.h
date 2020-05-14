#ifndef WINDOWSSPEECH4J_SRC_VOICE_H_
#define WINDOWSSPEECH4J_SRC_VOICE_H_

#include <string>
#include <sapi.h>

#include <sapi.h>
#include <string>

using std::wstring;

class Voice {
 private:
  wstring age;
  wstring gender;
  wstring languageCode;
  wstring name;
  wstring sharedPronunciation;
  wstring vendor;
  wstring version;
  ISpObjectToken * voiceToken;
 public:
  Voice(wstring age, wstring gender, wstring languageCode, wstring name,
		wstring sharedPronunciation, wstring vendor, wstring version, ISpObjectToken * voiceToken);
  wstring getAge() const;
  wstring getGender() const;
  wstring getLanguageCode() const;
  wstring getName() const;
  wstring getSharedPronunciation() const;
  wstring getVendor() const;
  wstring getVersion() const;
  size_t getHashCode();
  ISpObjectToken * getVoiceToken() const;
};


#endif