#include "Handle.h"

/**
 * Handles result of COM interface initialization
 * @param result of initializing COM interface
 * @throws DriverException
 * @return message for the logger
 */
void Handle::handleInitialize(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case E_INVALIDARG:
	  throw DriverException(Constants::EXCEPTION_INVALID_ARGUMENT,
							Constants::INITIALIZE_INVALID);
	case E_OUTOFMEMORY:
	  throw DriverException(Constants::EXCEPTION_OUT_OF_MEMORY,
							Constants::INITIALIZE_MEMORY);
	case E_UNEXPECTED:
	  throw DriverException(Constants::EXCEPTION_UNEXPECTED,
							Constants::INITIALIZE_UNEXPECTED);
	default:
	  throw DriverException(Constants::EXCEPTION_UNKNOWN,
							Constants::INITIALIZE_UNKNOWN);
  }
}

/**
 * Handles result of creating speech client instance
 * @param result of creating speech client instance
 * @throws DriverException
 */
void Handle::handleCreateInstance(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case REGDB_E_CLASSNOTREG:
	  throw DriverException(Constants::EXCEPTION_CLASS_NOT_FOUND,
							Constants::INSTANCE_NOT_FOUND);
	case CLASS_E_NOAGGREGATION:
	  throw DriverException(Constants::EXCEPTION_CREATION_FAILED,
							Constants::INSTANCE_AGGREGATE);
	case E_NOINTERFACE:
	  throw DriverException(Constants::EXCEPTION_CREATION_FAILED,
							Constants::INSTANCE_INTERFACE);
	case E_POINTER:
	  throw DriverException(Constants::EXCEPTION_NULL_ARGUMENT,
							Constants::INSTANCE_NULL);
	default:
	  throw DriverException(Constants::EXCEPTION_UNKNOWN,
							Constants::INSTANCE_UNKNOWN);
  }
}

void Handle::handleSetVolume(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case E_INVALIDARG:
	  throw DriverException(Constants::EXCEPTION_INVALID_ARGUMENT,
							Constants::SET_VOLUME_INVALID_ARG);
	default: break;
  }
}

void Handle::handleGetVolume(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case E_POINTER:
	  throw DriverException(Constants::EXCEPTION_NULL_ARGUMENT,
							Constants::GET_VOLUME_POINTER);
	default: break;
  }
}

void Handle::handleSetRate(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case E_INVALIDARG:
	  throw DriverException(Constants::EXCEPTION_INVALID_ARGUMENT,
							Constants::SET_RATE_INVALID_ARG);
	default: break;
  }
}

void Handle::handleGetRate(HRESULT result) {
  switch (result) {
	case S_OK: return;
	case E_POINTER:
	  throw DriverException(Constants::EXCEPTION_NULL_ARGUMENT,
							Constants::GET_RATE_POINTER);
	default: break;
  }
}