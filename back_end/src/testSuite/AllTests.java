package testSuite;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

/**
 * Runs all test cases.
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
@RunWith(Suite.class)
@SuiteClasses({
        AccountTest.class,
        TicketTest.class,
        RefundTest.class
})
public class AllTests {

}
