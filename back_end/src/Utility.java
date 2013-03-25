import java.util.Arrays;

public class Utility {

	 /**
     * A static method for creating a series of characters of arbitrary length
     * 
     * @param unit A character which the line will be made up of
     * @param length the length of the series
     * @return A series of characters
     */
    public static String createLine(final char unit, final int length) {
        final char[] line = new char[length];
        Arrays.fill(line, unit);
        return new String(line);
    }
}
