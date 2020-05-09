#include "SpeechDriver.h"
#include <iostream>

SpeechDriver* SpeechDriver::instance{nullptr};
std::mutex SpeechDriver::mutex;

/**
 * Thread safe method for obtaining the singleton instance
 * @return singleton instance of the SpeechDriver class
 */
SpeechDriver *SpeechDriver::getInstance() {
    if(instance == nullptr){
        std::lock_guard<std::mutex> lock(mutex);
        if(instance == nullptr){
            instance = new SpeechDriver();
        }
    }
    return instance;
}

/**
 * Initializes the COM library and creates voice instancec
 * @link https://docs.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-coinitializeex
 * @Link https://docs.microsoft.com/en-us/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance
 */
void SpeechDriver::initialize(JNIEnv * env, jobject object) {
    this->utility = new DriverUtility(env, object);
    HRESULT init = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    switch(init){
        case S_OK:
            utility->info("Initialized COM interface");
            break;
        case S_FALSE:
            utility->info("COM interface was already initialized");
            break;
        case E_INVALIDARG:
            utility->throwException(EXCEPTION_INVALID_ARGUMENT, "Invalid argument");
            return;
        case E_OUTOFMEMORY:
            utility->throwException(EXCEPTION_INVALID_ARGUMENT, "Invalid argument");

        case E_UNEXPECTED:
            return;
    }
    HRESULT instance = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void **) &spVoice);
}


SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
    CoUninitialize();
}


