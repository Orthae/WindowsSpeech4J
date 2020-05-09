package orthae.com.github.windowsspeech4j;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class SpeechDriverAdapter {

  private final Logger logger;

  public SpeechDriverAdapter(){
    logger = LogManager.getLogger("SpeechDriver");
  }

  public void info(String message){
    logger.info(message);
  }

  public void warn(String message){
    logger.warn(message);
  }

  public void error(String message){
    logger.error(message);
  }

  public native void initialize();

}
