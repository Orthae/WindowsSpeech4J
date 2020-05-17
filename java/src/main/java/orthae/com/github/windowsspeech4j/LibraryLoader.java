package orthae.com.github.windowsspeech4j;

import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

class LibraryLoader {

  public void validateSystemVersion() {
    final String systemName = getSystemName();
    if (!systemName.contains("Windows 10") && !systemName.contains("Windows 8.1") &&
        !systemName.contains("Windows 8") && !systemName.contains("Windows 7") &&
        !systemName.contains("Windows Vista")) {
      throw new SpeechDriverException(0, "System is not supported");
    }
  }

  public String getSystemName() {
    return System.getProperty("os.name");
  }

  public void loadDriver() throws IOException {
    final String libraryName = "WindowsSpeech4J.dll";
    final Path libraryPath = getLibraryPath(libraryName);
    InputStream stream = getResourceAsStream(libraryName);
    deleteExisting(libraryPath);
    extractLibrary(libraryPath, stream);
    loadLibrary(libraryPath);
  }

  public Path getLibraryPath(String libraryName) {
    return Paths.get(System.getenv("TEMP"), libraryName);
  }

  public void loadLibrary(Path libraryPath) {
    System.load(libraryPath.toAbsolutePath().toString());
  }

  public void extractLibrary(Path libraryPath, InputStream stream) throws IOException {
    Files.copy(stream, libraryPath);
  }

  public void deleteExisting(Path libraryPath) throws IOException {
    Files.deleteIfExists(libraryPath);
  }

  public InputStream getResourceAsStream(String libraryName) {
    return SpeechClient.class.getResourceAsStream(libraryName);
  }
}
