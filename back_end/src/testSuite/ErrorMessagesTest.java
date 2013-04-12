package testSuite;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import main.ErrorMessages;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the {@link ErrorMessages} class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class ErrorMessagesTest {

    /**
     * An invalid message key
     */
    private String invalidKey;

    /**
     * The resulting invalid message
     */
    private String invalidMessage;

    /**
     * Set up an invalid message string
     */
    @Before
    public void setUp() {
        this.invalidKey = "XXX";
        this.invalidMessage = "!XXX!";
    }

    /**
     * Test how {@link ErrorMessages} functions when an invalid message key is used.
     */
    @Test
    public void failGetString() {
        Assert.assertEquals(this.invalidMessage, ErrorMessages.getString(this.invalidKey));
    }

    /**
     * Test {@link ErrorMessages}'s private constructor   
     */
    @Test
    public void constructor() {
        Constructor<ErrorMessages> constructor = null;

        try {
            constructor = ErrorMessages.class.getDeclaredConstructor();
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
    }
}
