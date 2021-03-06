package orthae.com.github.windowsspeech4j;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class SpeechClientTest {

  private SpeechDriverAdapter adapter;
  private LibraryLoader loader;
  private SpeechClient client;

  @BeforeEach
  void setup() {
    this.adapter = mock(SpeechDriverAdapter.class);
    this.loader = mock(LibraryLoader.class);
    this.client = new SpeechClient(adapter, loader);
  }


  @Test
  void constructor() throws IOException {
    final SpeechDriverAdapter adapter = mock(SpeechDriverAdapter.class);
    final LibraryLoader loader = mock(LibraryLoader.class);

    new SpeechClient(adapter, loader);

    verify(loader, times(1)).loadLibrary();
    verify(adapter, times(1)).initialize();
  }

  @Test
  void constructorInitFailure() {
    final SpeechDriverException exception = mock(SpeechDriverException.class);
    final SpeechDriverAdapter adapter = mock(SpeechDriverAdapter.class);
    final LibraryLoader loader = mock(LibraryLoader.class);
    doThrow(exception).when(adapter).initialize();

    assertThrows(SpeechDriverException.class, () -> new SpeechClient(adapter, loader));
  }

  @Test
  void constructorLoadFailure() throws IOException {
    final IOException exception = mock(IOException.class);
    final SpeechDriverAdapter adapter = mock(SpeechDriverAdapter.class);
    final LibraryLoader loader = mock(LibraryLoader.class);
    doThrow(exception).when(loader).loadLibrary();

    assertThrows(UncheckedIOException.class, () -> new SpeechClient(adapter, loader));
  }

  @ParameterizedTest
  @ValueSource(shorts = {0, 5, 10, 50, 100})
  void setVolumeInRange(short volume) {
    client.setVolume(volume);

    verify(adapter, times(1)).setVolume(eq(volume));
  }

  @ParameterizedTest
  @ValueSource(ints = {-5, -10, -50, -100})
  void setVolumeBelowRange(int volume) {
    client.setVolume(volume);

    verify(adapter, times(1)).setVolume((short) 0);
  }

  @ParameterizedTest
  @ValueSource(shorts = {150, 200, 300, 500})
  void setVolumeAboveRange(int volume) {
    client.setVolume(volume);

    verify(adapter, times(1)).setVolume((short) 100);
  }

  @ParameterizedTest
  @ValueSource(shorts = {-10, -5, 0, 5, 10})
  void setRateInRange(short rate) {
    client.setRate(rate);

    verify(adapter, times(1)).setRate(eq(rate));
  }

  @ParameterizedTest
  @ValueSource(ints = {-15, -30, -50, -100})
  void setRateBelowRange(int rate) {
    client.setRate(rate);

    verify(adapter, times(1)).setRate((short) -10);
  }

  @ParameterizedTest
  @ValueSource(shorts = {15, 30, 50, 100})
  void setRateAboveRange(int rate) {
    client.setRate(rate);

    verify(adapter, times(1)).setRate((short) 10);
  }


  @ParameterizedTest
  @ValueSource(shorts = {0, 5, 10, 50, 100})
  void getVolume(short volume) {
    when(adapter.getVolume()).thenReturn(volume);

    final int result = client.getVolume();

    verify(adapter, times(1)).getVolume();
    assertEquals(volume, result);
  }

  @ParameterizedTest
  @ValueSource(shorts = {-10, -5, 0, 5, 10})
  void getRate(short rate) {
    when(adapter.getRate()).thenReturn(rate);

    final int result = client.getRate();

    verify(adapter, times(1)).getRate();
    assertEquals(rate, result);
  }

  @ParameterizedTest
  @ValueSource(strings = {"AA", "BB", "CC", "DD", "EE"})
  void setVoice(String hash){
    final Voice voice = mock(Voice.class);
    when(voice.getVoiceHash()).thenReturn(hash);

    client.setVoice(voice);

    verify(adapter, times(1)).setVoice(hash);
  }

  @Test
  void setVoiceNull(){
    client.setVoice(null);

    verify(adapter, never()).setVoice(anyString());
  }

  @Test
  void getVoices(){
    final Voice v1 = mock(Voice.class);
    final Voice v2 = mock(Voice.class);
    final Voice v3 = mock(Voice.class);
    final Voice[] voices = new Voice[]{v1, v2 ,v3};
    when(adapter.getVoices()).thenReturn(voices);

    final List<Voice> result = client.getVoices();

    assertNotNull(result);
    assertArrayEquals(voices, result.toArray());
  }

  @Test
  void speak(){
    final String text = "Test";

    client.speak(text);

    verify(adapter, times(1)).speak(text);
  }

  @Test
  void speakEmpty(){
    client.speak("");

    verify(adapter, never()).speak(anyString());
  }

  @Test
  void speakNull(){
    client.speak(null);

    verify(adapter, never()).speak(anyString());
  }
}