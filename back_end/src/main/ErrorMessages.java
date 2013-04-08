package main;

import java.util.MissingResourceException;
import java.util.ResourceBundle;

/**
 * Used to print error messages to the console's output
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class ErrorMessages {

    /**
     * The location of all of the error string
     */
    private static final ResourceBundle bundle = ResourceBundle.getBundle("main.messages");

    /**
     * Create an error message given the type of message and the error message.
     *
     * @param type the type of error message
     * @param message the error message
     */
    public static void printError(final String type, final String message) {
        System.out.printf("ERROR: %s %s%n", getString(type), getString(message));
    }

    /**
     * Get an error string
     * 
     * @param key a key for an error string
     * @return the string corresponding to the key
     */
    public static String getString(final String key) {
        try {
            return bundle.getString(key);
        } catch (final MissingResourceException e) {
            return '!' + key + '!';
        }
    }
}
