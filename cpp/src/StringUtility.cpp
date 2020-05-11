#include <string>
#include "StringUtility.h"

StringUtility::StringUtility(JNIEnv *env) {
  this->env = env;
}

std::wstring StringUtility::convertString(jstring javaString) {
  std::wstring cppString;
  const jchar* javaChars = env->GetStringChars(javaString, nullptr);

  jsize stringLength = env->GetStringLength(javaString);
  cppString.assign(javaChars, javaChars + stringLength);
  env->ReleaseStringChars(javaString, javaChars);
  return cppString;
}