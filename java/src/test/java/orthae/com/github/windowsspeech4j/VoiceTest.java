package orthae.com.github.windowsspeech4j;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class VoiceTest {

  @Test
  void constructor() {
    final String age = "SomeAge";
    final String gender = "SomeGender";
    final String languageCode = "SomeLanguageCode";
    final String name = "SomeName";
    final String sharedPronunciation = "SomeSharedPronunciation";
    final String vendor = "SomeVendor";
    final String version = "SomeVersion";
    final String voiceHash = "SomeVoiceHash";

    final Voice voice = new Voice(age, gender, languageCode, name,
        sharedPronunciation, vendor, version, voiceHash);

    assertNotNull(voice);
    assertEquals(age, voice.getAge());
    assertEquals(gender, voice.getGender());
    assertEquals(languageCode, voice.getLanguageCode());
    assertEquals(name, voice.getName());
    assertEquals(sharedPronunciation, voice.getSharedPronunciation());
    assertEquals(vendor, voice.getVendor());
    assertEquals(version, voice.getVersion());
    assertEquals(voiceHash, voice.getVoiceHash());
  }

}