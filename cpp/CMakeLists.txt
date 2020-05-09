cmake_minimum_required(VERSION 3.14)
project(WindowsSpeech4J)

set(CMAKE_CXX_STANDARD 11)

add_library(WindowsSpeech4J SHARED
            src/SpeechDriver.cpp
            src/SpeechDriver.h
            src/SpeechDriverAdapter.cpp
            src/AdapterUtility.cpp
            src/AdapterUtility.h)