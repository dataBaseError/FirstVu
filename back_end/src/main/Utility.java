package main;

import java.util.Arrays;

/**
 * a helper class responsible for adding the additional spaces for output formatting
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

public final class Utility {

    private Utility() {
    }

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
