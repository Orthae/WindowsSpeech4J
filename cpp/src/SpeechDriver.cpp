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
void SpeechDriver::initialize() {
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_ISpVoice, (void **) &spVoice);
}


SpeechDriver::SpeechDriver() = default;

SpeechDriver::~SpeechDriver() {
    CoUninitialize();
}


