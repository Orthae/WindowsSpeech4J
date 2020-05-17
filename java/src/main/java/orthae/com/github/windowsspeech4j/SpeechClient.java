package orthae.com.github.windowsspeech4j;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.UncheckedIOException;

public class SpeechClient {

  private Logger logger = LogManager.getLogger(SpeechClient.class);
  private SpeechDriverAdapter speechDriver;
  private LibraryLoader libraryLoader;

  public SpeechClient(SpeechDriverAdapter speechDriver, LibraryLoader libraryLoader) {
    this.speechDriver = speechDriver;
    this.libraryLoader = libraryLoader;
    try {
      libraryLoader.loadLibrary();
      speechDriver.initialize();
    } catch (SpeechDriverException exception) {
      logger.error("Failed to initialize speech driver.");
      throw exception;
    } catch (IOException exception) {
      logger.error("Failed to load driver library.");
      throw new UncheckedIOException(exception);
    }
  }


}
