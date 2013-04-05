package testSuite;

import static org.junit.Assert.*;
import junit.framework.Assert;

import main.Account;
import main.AuxiliaryTransaction;
import main.Utility;

import org.junit.Before;
import org.junit.Test;

public class UtilityTest {

	private String test;
	
	/**
     * Set up the AuxiliaryTransaction transaction
     */
    @Before
    public void setUp() {
        test = "0000000000";
    }  
    
	@Test
	public void testCreateLine() {
		assertEquals(Utility.createLine('0', 10), test);
	}

}
