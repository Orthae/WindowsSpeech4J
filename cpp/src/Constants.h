#ifndef WINDOWSSPEECH4J_CONSTANTS_H
#define WINDOWSSPEECH4J_CONSTANTS_H

class Constants {
 public:
  static inline std::string const CONSTRUCTOR_METHOD{"<init>"};

  // Logger constants
  static inline std::string const ADAPTER_LOG_INFO_SIGNATURE{
	  "(Ljava/lang/String;)V"};
  static inline std::string const ADAPTER_LOG_INFO_NAME{"info"};
  static inline std::string const ADAPTER_LOG_WARN_SIGNATURE{
	  "(Ljava/lang/String;)V"};
  static inline std::string const ADAPTER_LOG_WARN_NAME{"warn"};
  static inline std::string const ADAPTER_LOG_ERROR_SIGNATURE{
	  "(Ljava/lang/String;)V"};
  static inline std::string const ADAPTER_LOG_ERROR_NAME{"error"};

  // Exception constants
  static inline std::string const EXCEPTION_CLASS{
	  "orthae/com/github/windowsspeech4j/exception/SpeechDriverException"};
  static inline std::string const EXCEPTION_CONSTRUCTOR_SIGNATURE{
	  "(ILjava/lang/String;)V"};
  static inline int const EXCEPTION_UNKNOWN{0};
  static inline int const EXCEPTION_OUT_OF_MEMORY{1};
  static inline int const EXCEPTION_UNEXPECTED{2};
  static inline int const EXCEPTION_INVALID_ARGUMENT{3};
};
#endif