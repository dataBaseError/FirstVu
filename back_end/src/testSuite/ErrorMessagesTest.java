package testSuite;

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
}
