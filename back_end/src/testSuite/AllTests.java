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
        AuxiliaryTransactionTest.class,
        BackendTest.class,
        CondLoopTest.class,
        ErrorMessagesTest.class,
        EventTransactionTest.class,
        FileIOTest.class,
        RefundTest.class,
        TicketTest.class,
        TransactionsTest.class,
        UtilityTest.class,
})
public class AllTests {

}
