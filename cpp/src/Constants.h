#ifndef WINDOWSSPEECH4J_CONSTANTS_H
#define WINDOWSSPEECH4J_CONSTANTS_H

class Constants {
 public:
  static inline std::string const CONSTRUCTOR_METHOD{"<init>"};

  // Voice constants
  static inline std::string const VOICE_SIGNATURE{
	  "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"};
  static inline std::string const VOICE_CLASS{"orthae/com/github/windowsspeech4j/Voice"};
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

  //Logger messages
  static inline std::string const INITIALIZE_SUCCESS{"COM interface has been initialized."};
  static inline std::string const INITIALIZE_ALREADY{"COM interface was already initialized."};
  static inline std::string const
	  INITIALIZE_INVALID{"COM interface received Invalid argument, this should not happen."};
  static inline std::string const INITIALIZE_MEMORY{"System ran out the memory while initializing COM interface."};
  static inline std::string const INITIALIZE_UNEXPECTED{
	  "Encountered unexpected exception while initializing COM interface."};
  static inline std::string const INITIALIZE_UNKNOWN{
	  "Encountered unknown exception while initializing COM interface."};

  static inline std::string const INSTANCE_SUCCESS{
	  "Speech client had been created"};
  static inline std::string const INSTANCE_NOT_FOUND{"Could not find speech client class in system registry."};
  static inline std::string const INSTANCE_AGGREGATE{"Speech client cannot be created as aggregate."};
  static inline std::string const INSTANCE_INTERFACE{"Speech client doesn't implements specified interface."};
  static inline std::string const INSTANCE_NULL{"Passed null as client pointer, this should not happen."};
  static inline std::string const
	  INSTANCE_UNKNOWN{"Encountered unknown exception while creating speech client instance."};

  static inline std::string const VOICE_SET_VOLUME_INVALID_ARG{
    "Passed invalid argument to setVolume, this should not happen"};

  // Exception constants
  static inline std::string const EXCEPTION_CLASS{
	  "orthae/com/github/windowsspeech4j/exception/SpeechDriverException"};
  static inline std::string const EXCEPTION_CONSTRUCTOR_SIGNATURE{
	  "(ILjava/lang/String;)V"};
  static inline int const EXCEPTION_UNKNOWN{0};
  static inline int const EXCEPTION_OUT_OF_MEMORY{1};
  static inline int const EXCEPTION_UNEXPECTED{2};
  static inline int const EXCEPTION_INVALID_ARGUMENT{3};
  static inline int const EXCEPTION_NULL_ARGUMENT{4};
  static inline int const EXCEPTION_CLASS_NOT_FOUND{5};
  static inline int const EXCEPTION_CREATION_FAILED{6};
};
#endif