package main;

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
     * Create an error message given the type of message and the error message.
     *
     * @param type the type of error message
     * @param message the error message
     */
    public static void printError(final String type, final String message) {
        System.out.printf("ERROR: %s %s%n", type, message);
    }
}
