#ifndef CPP_SPEECHDRIVER_H
#define CPP_SPEECHDRIVER_H
#endif

#include <sapi.h>
#include <sphelper.h>
#include <mutex>

class SpeechDriver {
private:
    static SpeechDriver * instance;
    static std::mutex mutex;
    SpeechDriver();
    ~SpeechDriver();
    ISpVoice * spVoice{};
public:
    static SpeechDriver * getInstance();
    void initialize();
};