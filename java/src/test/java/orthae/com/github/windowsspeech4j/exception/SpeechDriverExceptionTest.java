package orthae.com.github.windowsspeech4j.exception;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static orthae.com.github.windowsspeech4j.exception.SpeechDriverException.*;
class SpeechDriverExceptionTest {


  @Test
  void cppConstructorUnknown() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(0, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.UNKNOWN, exception.getType());
  }

  @Test
  void cppConstructorOutOfMemory() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(1, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.OUT_OF_MEMORY, exception.getType());
  }

  @Test
  void cppConstructorUnexpected() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(2, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.UNEXPECTED, exception.getType());
  }

  @Test
  void cppConstructorInvalidArg() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(3, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.INVALID_ARGUMENT, exception.getType());
  }

  @Test
  void cppConstructorNullArg() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(4, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.NULL_ARGUMENT, exception.getType());
  }

  @Test
  void cppConstructorClassNotFound() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(5, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.CLASS_NOT_FOUND, exception.getType());
  }

  @Test
  void cppConstructorCreationFailed() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(6, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.CREATION_FAILED, exception.getType());
  }


  @Test
  void cppConstructorDefault() {
    final String message = "TestMessage";
    final SpeechDriverException exception = new SpeechDriverException(-1, message);

    assertEquals(message, exception.getMessage());
    assertEquals(Type.UNDEFINED, exception.getType());
  }

}