#ifndef WINDOWSSPEECH4J_CONSTANTS_H
#define WINDOWSSPEECH4J_CONSTANTS_H

const char *const CONSTRUCTOR_METHOD = "<init>";

const char *const ADAPTER_LOG_INFO_SIGNATURE = "(Ljava/lang/String;)V";
const char *const ADAPTER_LOG_INFO_NAME = "info";

const char *const ADAPTER_LOG_WARN_SIGNATURE = "(Ljava/lang/String;)V";
const char *const ADAPTER_LOG_WARN_NAME = "warn";

const char *const ADAPTER_LOG_ERROR_SIGNATURE = "(Ljava/lang/String;)V";
const char *const ADAPTER_LOG_ERROR_NAME = "error";


const char *const EXCEPTION_CLASS = "orthae/com/github/windowsspeech4j/exception/SpeechDriverException";
const char *const EXCEPTION_CONSTRUCTOR_SIGNATURE = "(ILjava/lang/String;)V";
const int EXCEPTION_UNKNOWN = 0;
const int EXCEPTION_OUT_OF_MEMORY = 1;
const int EXCEPTION_UNEXPECTED = 2;
const int EXCEPTION_INVALID_ARGUMENT = 3;
#endif