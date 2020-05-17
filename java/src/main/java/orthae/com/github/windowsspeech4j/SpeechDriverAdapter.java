package orthae.com.github.windowsspeech4j;

public class SpeechDriverAdapter {

  public native void initialize();

  public native void setVolume(short volume);

  public native short getVolume();

  public native void setRate(short rate);

  public native short getRate();

  public native void setVoice(String voiceHash);

  public native Voice[] getVoices();

  public native void speak(String text);
}
