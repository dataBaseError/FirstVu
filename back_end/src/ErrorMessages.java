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
     * @param file the file that is involved in the error, null if no file is involved
     */
    public static void printError(final String type, final String message, final String file) {
        if (file == null) {
            // Fatal Error
        } else {
            // Constraint Error
        }
    }
}
