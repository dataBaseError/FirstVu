package testSuite;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;
import org.junit.runners.Suite.SuiteClasses;

@RunWith(Suite.class)
@SuiteClasses({
        AccountTest.class,
        TicketTest.class,
        RefundTest.class
})
public class AllTests {

}
