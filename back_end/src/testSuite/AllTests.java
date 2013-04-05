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
        UtilityTest.class,
        AccountTest.class,
        TicketTest.class,
        RefundTest.class,
        AuxiliaryTransactionTest.class,
        EventTransactionTest.class,
        ErrorMessagesTest.class,
        FileIOTest.class
})
public class AllTests {

}
