package testSuite;

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
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        this.line = "0000000000";
    }

    /**
     * Test to see if Utility's constructor is visible
     */
    @Test()
    public void coverUtility() {
        new Utility();
    }

    /**
     * Tests the creation of a line of characters
     */
    @Test
    public void createLine() {
        Assert.assertEquals(Utility.createLine('0', 10), this.line);
    }
}
