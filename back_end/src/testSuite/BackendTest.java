package testSuite;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import junitx.framework.FileAssert;
import main.Backend;
import main.ErrorMessages;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Tests the {@link Backend} class
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class BackendTest {

    /**
     * Backs up the default standard output
     */
    private static final PrintStream stdout = System.out;

    /**
     * Backs up the default standard error output
     */
    private static final PrintStream stderr = System.err;

    /**
     * The content of the redirected output
     */
    private final ByteArrayOutputStream outContent = new ByteArrayOutputStream();

    /**
     * The content of the redirected error output
     */
    private final ByteArrayOutputStream errContent = new ByteArrayOutputStream();

    /**
     * Arguments for a successful run
     */
    private final String[] argsSuccess = new String[5];

    /**
     * Normal arguments for a typical run
     */
    private final String[] args = new String[4];

    /**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        System.setOut(new PrintStream(this.outContent));
        System.setErr(new PrintStream(this.errContent));

        this.argsSuccess[0] = "tests/full_test/full.etf";
        this.argsSuccess[1] = "tests/global/glob_account.inp";
        this.argsSuccess[2] = "tests/global/glob_available_tickets.inp";
        this.argsSuccess[3] = "tests/output/newaccounts.out";
        this.argsSuccess[4] = "tests/output/newtickets.out";
    }

    /**
     * Restore the stdout and stderr stream
     */
    @After
    public void cleanUpStreams() {
        System.setOut(new PrintStream(stdout));
        System.setErr(new PrintStream(stderr));
    }

    /**
     * Tests what happens when the main function is executed with too few arguments
     */
    @Test
    public void mainTooFewArguments() {
        Backend.main(this.args);
        Assert.assertEquals("ERROR: " + ErrorMessages.getString("INPUTS_ERROR_TYPE") + " "
                + ErrorMessages.getString("INPUT_FILES_MISSING") + "\n", this.outContent.toString());
    }

    /**
     * Tests a successful execution
     */
    @Test
    public void mainInputSuccess() {
        Backend.main(this.argsSuccess);

        FileAssert.assertEquals(new File(this.argsSuccess[3]), new File("tests/full_test/full.uao"));
        FileAssert.assertEquals(new File(this.argsSuccess[4]), new File("tests/full_test/full.ato"));
    }

    /**
     * Test {@link Backend}'s private constructor  
     */
    @Test
    public void constructor() {
        Constructor<Backend> constructor = null;

        try {
            constructor = Backend.class.getDeclaredConstructor();
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
