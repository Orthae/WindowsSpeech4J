#include "DriverUtility.h"

DriverUtility::DriverUtility(JNIEnv *env, jobject object) {
  this->exceptionUtility = new ExceptionUtility(env);
  this->stringUtility = new TypeUtility(env);
  this->loggerUtility = new LoggerUtility(env, object);
  this->handleUtility = new HandleUtility(loggerUtility);
}

DriverUtility::~DriverUtility() {
  delete this->exceptionUtility;
  delete this->stringUtility;
}

void DriverUtility::throwException(DriverException const &exception) {
  exceptionUtility->throwException(exception);
}

std::wstring DriverUtility::convertString(jstring javaString) {
  return stringUtility->convertString(javaString);
}

void DriverUtility::error(std::string const &message) {
  loggerUtility->error(message);
}

void DriverUtility::warn(std::string const &message) {
  loggerUtility->warn(message);
}

void DriverUtility::info(std::string const &message) {
  loggerUtility->info(message);
}

void DriverUtility::handleInitialize(HRESULT result) {
  handleUtility->handleInitialize(result);
}

void DriverUtility::handleCreateInstance(HRESULT result) {
  handleUtility->handleCreateInstance(result);
}

jobjectArray DriverUtility::mapVoices(std::vector<Voice> voices) {
  return stringUtility->mapVoices(voices);
}

Voice DriverUtility::mapVoice(jobject jObject) {
  return stringUtility->mapVoice(jObject);
}