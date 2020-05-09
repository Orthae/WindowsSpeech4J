package orthae.com.github;

import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.apache.logging.log4j.core.config.Configurator;
import org.apache.logging.log4j.core.config.DefaultConfiguration;
import orthae.com.github.windowsspeech4j.SpeechDriverAdapter;

import java.nio.file.Paths;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        Logger logger = LogManager.getLogger();
        Configurator.initialize(new DefaultConfiguration());
        Configurator.setRootLevel(Level.INFO);
        logger.info("This is my first log4j's statement");
        System.load(Paths.get("WindowsSpeech4J.dll").toAbsolutePath().toString());
        SpeechDriverAdapter adapter = new SpeechDriverAdapter();
        adapter.initialize();
    }
}
