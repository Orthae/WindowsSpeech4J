#ifndef CPP_SPEECHDRIVER_H
#define CPP_SPEECHDRIVER_H
#endif

#include <sapi.h>
#include <sphelper.h>
#include <mutex>
#include "DriverUtility.h"

class SpeechDriver {
private:
    DriverUtility * utility;
    static SpeechDriver * instance;
    static std::mutex mutex;
    SpeechDriver();
    ~SpeechDriver();
    ISpVoice * spVoice;
public:
    static SpeechDriver * getInstance();
    void initialize(JNIEnv * env, jobject object);
};