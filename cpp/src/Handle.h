#ifndef WINDOWSSPEECH4J_SRC_HANDLE_H_
#define WINDOWSSPEECH4J_SRC_HANDLE_H_

#include <sapi.h>
#include "Constants.h"
#include "DriverException.h"

class Handle {
 public:
  static void handleInitialize(HRESULT result);
  static void handleCreateInstance(HRESULT result);
  static void handleSetVolume(HRESULT result);
  static void handleGetVolume(HRESULT result);
  static void handleSetRate(HRESULT result);
  static void handleGetRate(HRESULT result);
};

#endif //WINDOWSSPEECH4J_SRC_HANDLE_H_
