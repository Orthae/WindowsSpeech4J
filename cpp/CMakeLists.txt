cmake_minimum_required(VERSION 3.14)
project(WindowsSpeech4J)

set(CMAKE_CXX_STANDARD 17)

add_library(WindowsSpeech4J SHARED
            src/SpeechDriver.cpp
            src/SpeechDriver.h
            src/SpeechDriverAdapter.cpp
            src/DriverUtility.cpp
            src/DriverUtility.h
            src/Constants.h
            src/ExceptionUtility.cpp
            src/ExceptionUtility.h
            src/StringUtility.cpp
            src/StringUtility.h)