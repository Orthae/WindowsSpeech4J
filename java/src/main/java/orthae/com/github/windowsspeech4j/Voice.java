package orthae.com.github.windowsspeech4j;

import lombok.Getter;

@Getter
public class Voice {

  private final String age;
  private final String gender;
  private final String languageCode;
  private final String name;
  private final String sharedPronunciation;
  private final String vendor;
  private final String version;
  private final String voiceHash;

  public Voice(String age, String gender, String languageCode, String name, String sharedPronunciation,
               String vendor, String version, String voiceHash) {
    this.age = age;
    this.gender = gender;
    this.languageCode = languageCode;
    this.name = name;
    this.sharedPronunciation = sharedPronunciation;
    this.vendor = vendor;
    this.version = version;
    this.voiceHash = voiceHash;
  }
}
