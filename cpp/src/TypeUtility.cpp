#include <string>
#include <iostream>
#include "TypeUtility.h"
#include "Constants.h"

TypeUtility::TypeUtility(JNIEnv *env) {
  this->env = env;
}

std::wstring TypeUtility::convertString(jstring javaString) {
  std::wstring cppString;
  const jchar *javaChars = env->GetStringChars(javaString, nullptr);

  jsize stringLength = env->GetStringLength(javaString);
  cppString.assign(javaChars, javaChars + stringLength);
  env->ReleaseStringChars(javaString, javaChars);
  return cppString;
}

jobjectArray TypeUtility::mapVoices(std::vector<Voice> voices) {
  jclass clazz = env->FindClass("orthae/com/github/windowsspeech4j/Voice");
  jmethodID constructor = env->GetMethodID(clazz,
										   Constants::CONSTRUCTOR_METHOD.c_str(),
										   "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
  jobjectArray ret = env->NewObjectArray(voices.size(), clazz, nullptr);

  for (size_t i = 0; i < voices.size(); i++) {
	jstring age =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getAge().c_str()),
					   voices[i].getAge().length());
	jstring gender =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getGender().c_str()),
					   voices[i].getGender().length());
	jstring languageCode =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getLanguageCode().c_str()),
					   voices[i].getLanguageCode().length());
	jstring name =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getName().c_str()),
					   voices[i].getName().length());
	jstring sharedPronunciation =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getSharedPronunciation().c_str()),
					   voices[i].getSharedPronunciation().length());
	jstring vendor =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getVendor().c_str()),
					   voices[i].getVendor().length());
	jstring version =
		env->NewString(reinterpret_cast<const jchar *>(voices[i].getVersion().c_str()),
					   voices[i].getVersion().length());

	std::wstring voiceHash = std::to_wstring(voices[i].getHashCode());
	jstring hash = env->NewString(reinterpret_cast<const jchar *>(voiceHash.c_str()),
								  voiceHash.length());

	jobject obj =
		env->NewObject(clazz, constructor, age, gender, languageCode, name,
					   sharedPronunciation, vendor, version, hash);
	env->SetObjectArrayElement(ret, i, obj);
  }
  return ret;
}

size_t TypeUtility::getVoiceHashCode(jstring hashString) {
  std::wstring cppString;
  const jchar *javaChars = env->GetStringChars(hashString, nullptr);
  jsize stringLength = env->GetStringLength(hashString);
  cppString.assign(javaChars, javaChars + stringLength);
  env->ReleaseStringChars(hashString, javaChars);
  return std::stoull(cppString);
}