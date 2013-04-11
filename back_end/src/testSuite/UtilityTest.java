package testSuite;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import main.Utility;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the Utility class which contains only static methods
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class UtilityTest {

    /**
     * The expected line
     */
    private String line;

    /** 
     * Set up the expected line
     */
    @Before
    public void setUp() {
        this.line = "0000000000";
    }

    /**
     * Tests the creation of a line of characters
     */
    @Test
    public void createLine() {
        Assert.assertEquals(this.line, Utility.createLine('0', 10));
    }

    /**
     * Test {@link Utility}'s private constructor  
     */
    @Test
    public void constructor() {
        Constructor<Utility> constructor = null;

        try {
            constructor = Utility.class.getDeclaredConstructor();
        } catch (final NoSuchMethodException e) {
            Assert.fail(e.toString());
        } catch (final SecurityException e) {
            Assert.fail(e.toString());
        }

        constructor.setAccessible(true);

        try {
            Assert.assertNotNull(constructor.newInstance());
        } catch (final InstantiationException e) {
            Assert.fail(e.toString());
        } catch (final IllegalAccessException e) {
            Assert.fail(e.toString());
        } catch (final IllegalArgumentException e) {
            Assert.fail(e.toString());
        } catch (final InvocationTargetException e) {
            Assert.fail(e.toString());
        }

        constructor.setAccessible(false);
    }
}
