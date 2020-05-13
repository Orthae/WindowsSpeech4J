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
        src/DriverUtility.cpp
        src/DriverUtility.h
        src/Constants.h
        src/ExceptionUtility.cpp
        src/ExceptionUtility.h
        src/StringUtility.cpp
        src/StringUtility.h
        src/LoggerUtility.cpp
        src/LoggerUtility.h
        src/DriverException.cpp
        src/DriverException.h
        src/HandleUtility.cpp
        src/HandleUtility.h)