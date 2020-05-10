package orthae.com.github.windowsspeech4j;

import java.nio.file.Paths;

public class WindowsSpeech4J {

    private final SpeechDriverAdapter speechDriver;

    public WindowsSpeech4J(SpeechDriverAdapter speechDriver) {
        this.speechDriver = speechDriver;
        System.load(Paths.get("WindowsSpeech4J.dll").toAbsolutePath().toString());
        speechDriver.initialize();;
    }

    public void speak(String text){
        speechDriver.speak(text);
    }

}
