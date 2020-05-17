package orthae.com.github.windowsspeech4j.exception;

import lombok.Getter;

@Getter
public class SpeechDriverException extends RuntimeException {
  private final SpeechDriverException.Type type;

  enum Type {
    UNKNOWN,
    OUT_OF_MEMORY,
    UNEXPECTED,
    INVALID_ARGUMENT,
    NULL_ARGUMENT,
    CLASS_NOT_FOUND,
    CREATION_FAILED,
    UNDEFINED
  }

  public SpeechDriverException(int exceptionType, String message) {
    super(message);
    switch (exceptionType) {
      case 0:
        this.type = Type.UNKNOWN;
        break;
      case 1:
        this.type = Type.OUT_OF_MEMORY;
        break;
      case 2:
        this.type = Type.UNEXPECTED;
        break;
      case 3:
        this.type = Type.INVALID_ARGUMENT;
        break;
      case 4:
        this.type = Type.NULL_ARGUMENT;
        break;
      case 5:
        this.type = Type.CLASS_NOT_FOUND;
        break;
      case 6:
        this.type = Type.CREATION_FAILED;
        break;
      default:
        this.type = Type.UNDEFINED;
    }
  }
}
