package orthae.com.github.windowsspeech4j.exception;

public class SpeechDriverException extends RuntimeException {
  private final int type;

  public SpeechDriverException(int exceptionType, String message) {
    super(message);
    this.type = exceptionType;
  }

  public int getType() {
    return type;
  }
}
