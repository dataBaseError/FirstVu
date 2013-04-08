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

    private static final String BUNDLE_NAME = "main.messages"; //$NON-NLS-1$

    private static final ResourceBundle RESOURCE_BUNDLE = ResourceBundle.getBundle(BUNDLE_NAME);

    /**
     * Create an error message given the type of message and the error message.
     *
     * @param type the type of error message
     * @param message the error message
     */
    public static void printError(final String type, final String message) {
        System.out.printf("ERROR: %s %s%n", getString(type), getString(message));
    }

    public static String getString(final String key) {
        try {
            return RESOURCE_BUNDLE.getString(key);
        } catch (final MissingResourceException e) {
            return '!' + key + '!';
        }
    }
}
