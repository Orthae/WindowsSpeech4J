cmake_minimum_required(VERSION 3.14)
project(WindowsSpeech4J)

set(CMAKE_CXX_STANDARD 17)

if (NOT DEFINED ENV{JAVA_HOME})
    message(FATAL_ERROR "JAVA_HOME is not set.")
endif ()

include_directories($ENV{JAVA_HOME}/include
        $ENV{JAVA_HOME}/include/win32)


add_library(WindowsSpeech4J SHARED
        src/SpeechDriver.cpp
        src/SpeechDriver.h
        src/SpeechDriverAdapter.cpp
        src/Constants.h
        src/Exception.cpp
        src/Exception.h
        src/Type.cpp
        src/Type.h
        src/DriverException.cpp
        src/DriverException.h
        src/Handle.cpp
        src/Handle.h
        src/Voice.cpp
        src/Voice.h
        )