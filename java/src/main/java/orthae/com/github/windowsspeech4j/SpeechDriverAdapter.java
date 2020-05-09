package orthae.com.github.windowsspeech4j;

public class SpeechDriverAdapter {


  public void log(String message){
    System.out.println("Logger message:" + message);
  }

  public native void initialize();

}
