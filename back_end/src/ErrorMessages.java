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
     * @param type the type of error message
     * @param message the error message
     */
    public static void printError(final String type, final String message) {
        System.out.printf("%s error: %s\n", type, message);
    }
}
