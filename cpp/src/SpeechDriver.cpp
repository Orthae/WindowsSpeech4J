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
void SpeechDriver::initialize(JNIEnv *env, jobject object) {
  this->env = env;
  this->utility = new DriverUtility(env, object);
  try {
	HRESULT initResult = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	handleInitialize(initResult);
	HRESULT instanceResult = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void **)&spVoice);
	handleCreateInstance(instanceResult);
  } catch (DriverException &exception) {
    utility->throwException(exception);
  }
}

/**
 * Handles result of COM interface initialization
 * @param result of initializing COM interface
 * @throws DriverException
 */
void SpeechDriver::handleInitialize(HRESULT result) {
  switch (result) {
	case S_OK: utility->info(Constants::INITIALIZE_SUCCESS);
	  return;
	case S_FALSE: utility->info(Constants::INITIALIZE_ALREADY);
	  return;
	case E_INVALIDARG: throw DriverException(Constants::EXCEPTION_INVALID_ARGUMENT, Constants::INITIALIZE_INVALID);
	case E_OUTOFMEMORY:throw DriverException(Constants::EXCEPTION_OUT_OF_MEMORY, Constants::INITIALIZE_MEMORY);
	case E_UNEXPECTED: throw DriverException(Constants::EXCEPTION_UNEXPECTED, Constants::INITIALIZE_UNEXPECTED);
	default: throw DriverException(Constants::EXCEPTION_UNKNOWN, Constants::INITIALIZE_UNKNOWN);
  }
}


/**
 * Handles result of creating speech client instance
 * @param result of creating speech client instance
 * @throws DriverException
 */
void SpeechDriver::handleCreateInstance(HRESULT result) {
  switch (result) {
	case S_OK: utility->info(Constants::INSTANCE_SUCCESS);
	case REGDB_E_CLASSNOTREG:
	  throw DriverException(Constants::EXCEPTION_CLASS_NOT_FOUND,
							Constants::INSTANCE_NOT_FOUND);
	case CLASS_E_NOAGGREGATION:
	  throw DriverException(Constants::EXCEPTION_CREATION_FAILED,
							Constants::INSTANCE_AGGREGATE);
	case E_NOINTERFACE: throw DriverException(Constants::EXCEPTION_CREATION_FAILED, Constants::INSTANCE_INTERFACE);
	case E_POINTER: throw DriverException(Constants::EXCEPTION_NULL_ARGUMENT, Constants::INSTANCE_NULL);
	default: break;
  }
}

void SpeechDriver::speak(jstring textToSpeak) {
  auto convertedText = utility->convertString(textToSpeak);
  spVoice->Speak(convertedText.c_str(), SVSFDefault, nullptr);
}


SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
  CoUninitialize();
}
