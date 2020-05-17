package orthae.com.github.windowsspeech4j;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Path;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class LibraryLoaderTest {

  private LibraryLoader libraryLoader;

  @BeforeEach
  void setup() {
    this.libraryLoader = spy(new LibraryLoader());
  }

  @ParameterizedTest
  @ValueSource(strings = {"Windows 10", "Windows 8.1", "Windows 8", "Windows 7", "Windows Vista"})
  void validateSystemVersion(String os) {
    when(libraryLoader.getSystemName()).thenReturn(os);

    libraryLoader.validateSystemVersion();
  }

  @ParameterizedTest()
  @ValueSource(strings = {"Windows 95", "Windows 98", "Windows ME", "MacOS", "Ubuntu"})
  void validateSystemVersionNonValid(String os) {
    when(libraryLoader.getSystemName()).thenReturn(os);

    assertThrows(SpeechDriverException.class, () -> libraryLoader.validateSystemVersion());
  }

  @Test
  void loadLibrarySuccess() throws IOException {
    final String libName = "WindowsSpeech4J.dll";
    final Path libPath = mock(Path.class);
    final InputStream libStream = mock(InputStream.class);
    when(libraryLoader.getLibraryPath(libName)).thenReturn(libPath);
    when(libraryLoader.getResourceAsStream(libName)).thenReturn(libStream);
    doNothing().when(libraryLoader).deleteExisting(libPath);
    doNothing().when(libraryLoader).extractLibrary(libPath, libStream);
    doNothing().when(libraryLoader).loadLibrary(libPath);

    libraryLoader.loadDriver();

    verify(libraryLoader, times(1)).getLibraryPath(libName);
    verify(libraryLoader, times(1)).getResourceAsStream(libName);
    verify(libraryLoader, times(1)).deleteExisting(libPath);
    verify(libraryLoader, times(1)).extractLibrary(libPath, libStream);
    verify(libraryLoader, times(1)).loadLibrary(libPath);
  }

}