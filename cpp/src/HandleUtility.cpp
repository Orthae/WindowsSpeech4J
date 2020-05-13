#include "HandleUtility.h"

HandleUtility::HandleUtility(LoggerUtility *logger){
  this->logger = logger;
}

/**
 * Handles result of COM interface initialization
 * @param result of initializing COM interface
 * @throws DriverException
 */
void HandleUtility::handleInitialize(HRESULT result) {
  switch (result) {
	case S_OK: logger->info(Constants::INITIALIZE_SUCCESS);
	  return;
	case S_FALSE: logger->info(Constants::INITIALIZE_ALREADY);
	  return;
	case E_INVALIDARG: throw DriverException(Constants::EXCEPTION_INVALID_ARGUMENT, Constants::INITIALIZE_INVALID);
	case E_OUTOFMEMORY:throw DriverException(Constants::EXCEPTION_OUT_OF_MEMORY, Constants::INITIALIZE_MEMORY);
	case E_UNEXPECTED: throw DriverException(Constants::EXCEPTION_UNEXPECTED, Constants::INITIALIZE_UNEXPECTED);
	default: throw DriverException(Constants::EXCEPTION_UNKNOWN, Constants::INITIALIZE_UNKNOWN);
  }
}

/**
 * Handles result of creating speech client instance
 * @param result of creating speech client instance
 * @throws DriverException
 */
void HandleUtility::handleCreateInstance(HRESULT result) {
  switch (result) {
	case S_OK: logger->info(Constants::INSTANCE_SUCCESS);
	  return;
	case REGDB_E_CLASSNOTREG:
	  throw DriverException(Constants::EXCEPTION_CLASS_NOT_FOUND,
							Constants::INSTANCE_NOT_FOUND);
	case CLASS_E_NOAGGREGATION:
	  throw DriverException(Constants::EXCEPTION_CREATION_FAILED,
							Constants::INSTANCE_AGGREGATE);
	case E_NOINTERFACE: throw DriverException(Constants::EXCEPTION_CREATION_FAILED, Constants::INSTANCE_INTERFACE);
	case E_POINTER: throw DriverException(Constants::EXCEPTION_NULL_ARGUMENT, Constants::INSTANCE_NULL);
	default: break;
  }
}