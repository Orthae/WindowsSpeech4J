package orthae.com.github.windowsspeech4j;

import org.junit.jupiter.api.Test;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.UncheckedIOException;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class SpeechClientTest {

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

}