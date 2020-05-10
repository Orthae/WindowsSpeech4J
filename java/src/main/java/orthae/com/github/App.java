package orthae.com.github;

import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.apache.logging.log4j.core.config.Configurator;
import org.apache.logging.log4j.core.config.DefaultConfiguration;
import orthae.com.github.windowsspeech4j.SpeechDriverAdapter;
import orthae.com.github.windowsspeech4j.WindowsSpeech4J;
import orthae.com.github.windowsspeech4j.exception.SpeechDriverException;

import java.nio.file.Paths;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Configurator.initialize(new DefaultConfiguration());
        Configurator.setRootLevel(Level.INFO);

        SpeechDriverAdapter adapter = new SpeechDriverAdapter();
        try {
            WindowsSpeech4J speech4J = new WindowsSpeech4J(adapter);
            speech4J.speak("test");
        } catch (SpeechDriverException e){
            System.out.println("Type is " + e.getType());
        }
    }
}
