package orthae.com.github.windowsspeech4j;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;

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

  public void setVolume(int volume) {
    if (volume < 0) {
      logger.warn("Volume below threshold, truncated to 0");
      volume = 0;
    }
    if (volume > 100) {
      logger.warn("Volume above threshold, truncated to 100");
      volume = 100;
    }
    speechDriver.setVolume((short) volume);
  }

  public int getVolume() {
    return speechDriver.getVolume();
  }

  public void setRate(int rate) {
    if (rate < -10) {
      logger.warn("Rate below threshold, truncated to -10");
      rate = -10;
    }
    if (rate > 10) {
      logger.warn("Rate above threshold, truncated to 10");
      rate = 10;
    }
    speechDriver.setRate((short) rate);
  }

  public int getRate() {
    return speechDriver.getRate();
  }


}
