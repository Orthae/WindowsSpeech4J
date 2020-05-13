#ifndef WINDOWSSPEECH4J_SRC_HANDLEUTILITY_H_
#define WINDOWSSPEECH4J_SRC_HANDLEUTILITY_H_

#include <sapi.h>
#include "LoggerUtility.h"
#include "Constants.h"
#include "DriverException.h"

class HandleUtility {
 private:
  LoggerUtility *logger;
 public:
  HandleUtility(LoggerUtility *utility);
  void handleInitialize(HRESULT result);
  void handleCreateInstance(HRESULT result);
};

#endif //WINDOWSSPEECH4J_SRC_HANDLEUTILITY_H_
