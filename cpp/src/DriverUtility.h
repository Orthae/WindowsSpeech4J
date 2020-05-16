#ifndef WINDOWSSPEECH4J_ADAPTERUTILITY_H
#define WINDOWSSPEECH4J_ADAPTERUTILITY_H

#include <jni.h>
#include <string>
#include <sapi.h>
#include "Constants.h"
#include "ExceptionUtility.h"
#include "HandleUtility.h"
#include "TypeUtility.h"
#include "LoggerUtility.h"
#include "DriverException.h"

class DriverUtility {
 private:
  ExceptionUtility *exceptionUtility;
  TypeUtility *stringUtility;
  LoggerUtility *loggerUtility;
  HandleUtility *handleUtility;
 public:
  DriverUtility(JNIEnv *env, jobject object);
  ~DriverUtility();
  void info(std::string const &message);
  void warn(std::string const &message);
  void error(std::string const &message);
  void throwException(DriverException const &exception);
  std::wstring convertString(jstring javaString);
  void handleInitialize(HRESULT result);
  void handleCreateInstance(HRESULT result);
  jobjectArray mapVoices(std::vector<Voice> voices);
  size_t getVoiceHashCode(jstring hashString);
};

#endif