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
										   "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
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
	jobject obj =
		env->NewObject(clazz, constructor, age, gender, languageCode, name, sharedPronunciation, vendor, version);
	env->SetObjectArrayElement(ret, i, obj);
  	std::cout << voices[i].getHashCode() <<std::endl;
  }
  return ret;
}

Voice TypeUtility::mapVoice(jobject jObject){
  jclass clazz = env->FindClass("orthae/com/github/windowsspeech4j/Voice");

  jfieldID jfAge =  env->GetFieldID(clazz, "age","Ljava/lang/String;");
  jstring jAge = (jstring)env->GetObjectField(jObject, jfAge);
  std::wstring age = convertString(jAge);

  jfieldID jfGender =  env->GetFieldID(clazz, "gender","Ljava/lang/String;");
  jstring jGender = (jstring)env->GetObjectField(jObject, jfGender);
  std::wstring gender = convertString(jGender);

  jfieldID jfLanguageCode =  env->GetFieldID(clazz, "languageCode","Ljava/lang/String;");
  jstring jLanguageCode = (jstring)env->GetObjectField(jObject, jfLanguageCode);
  std::wstring languageCode = convertString(jLanguageCode);

  jfieldID jfName =  env->GetFieldID(clazz, "name","Ljava/lang/String;");
  jstring jName = (jstring)env->GetObjectField(jObject, jfName);
  std::wstring name = convertString(jName);

  jfieldID jfSharedPronunciation =  env->GetFieldID(clazz, "sharedPronunciation","Ljava/lang/String;");
  jstring jSharedPronunciation = (jstring)env->GetObjectField(jObject, jfSharedPronunciation);
  std::wstring sharedPronunciation = convertString(jSharedPronunciation);

  jfieldID jfVendor =  env->GetFieldID(clazz, "vendor","Ljava/lang/String;");
  jstring jVendor = (jstring)env->GetObjectField(jObject, jfVendor);
  std::wstring vendor = convertString(jVendor);

  jfieldID jfVersion =  env->GetFieldID(clazz, "version","Ljava/lang/String;");
  jstring jVersion = (jstring)env->GetObjectField(jObject, jfVersion);
  std::wstring version = convertString(jVersion);

  return Voice(age,gender,languageCode,name,sharedPronunciation,vendor,version, nullptr);
}