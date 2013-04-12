package testSuite;

import java.io.File;

import main.Transactions;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

/**
 * Performs Condition and Loop Coverage on {@link Transactions#findNextLogout(int)} 
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class CondLoopTest {

    /**
     * The location of the test files
     */
    private static String tests = "./tests/";

    /** 
     * The location of the global user account file and ticket file
     */
    private static String global = tests + "global/";

    /**
     * The input user accounts file
     */
    private static String uao = global + "glob_account.inp";

    /**
     * The input ticket file
     */
    private static String ato = global + "glob_available_tickets.inp";

    /**
     * A sample new User Account file name
     */
    private static String uaoSample = global + "global.usr";

    /**
     * A sample new Tickets file name
     */
    private static String atoSample = global + "global.tic";

    /**
     * The location of the test daily transaction files for loop coverage
     */
    private static String etfs = tests + "loopcoverage/";

    /**
     * A daily transaction file that will never cover the loop
     */
    private static String zeroEtf = etfs + "zero.etf";

    /**
     * A daily transaction file that will cover the loop many times
     */
    private static String manyEtf = etfs + "many.etf";

    /**
     * A daily transaction file that will cover the loop once
     */
    private static String onceEtf = etfs + "one.etf";

    /**
     * A daily transaction file that will cover the loop twice
     */
    private static String twiceEtf = etfs + "twice.etf";

    /**
     * The location of the test daily transaction files for condition covreage
     */
    private static String ifs = tests + "condcoverage/";

    /**
     * A daily transaction file that will cause the if statement to be true
     */
    private static String trueEtf = ifs + "true.etf";

    /**
     * A daily transaction file that will cause the if statement to be false
     */
    private static String falseEtf = ifs + "false.etf";

    /**
     * Instance of a transaction that will never execute the loop
     */
    private Transactions transactionZero;

    /**
     * Instance of a transaction that will execute the loop once
     */
    private Transactions transactionOnce;

    /**
     * Instance of a transaction that will execute the loop twice
     */
    private Transactions transactionTwice;

    /**
     * Instance of a transaction that will execute the loop many times
     */
    private Transactions transactionMany;

    /**
     * Instance of a transaction that will cause the if statement to be true
     */
    private Transactions transactionTrue;

    /**
     * Instance of a transaction that will cause the if statement to be false
     */
    private Transactions transactionFalse;

    /**
     * A sample new user accounts file
     */
    private File uaoSampleFile;

    /**
     * A sample new ticket file
     */
    private File atoSampleFile;

    /**
     * Set up the transaction files and the output files
     */
    @Before
    public void setUp() {

        // Loop coverage
        this.transactionZero = new Transactions(zeroEtf, uao, ato, uaoSample, atoSample);
        this.transactionOnce = new Transactions(onceEtf, uao, ato, uaoSample, atoSample);
        this.transactionTwice = new Transactions(twiceEtf, uao, ato, uaoSample, atoSample);
        this.transactionMany = new Transactions(manyEtf, uao, ato, uaoSample, atoSample);

        // Condition coverage
        this.transactionTrue = new Transactions(trueEtf, uao, ato, uaoSample, atoSample);
        this.transactionFalse = new Transactions(falseEtf, uao, ato, uaoSample, atoSample);

        this.uaoSampleFile = new File(uaoSample);
        this.atoSampleFile = new File(atoSample);
    }

    /**
     * Delete the files created by {@link Transactions}
     */
    @After
    public void tearDown() {
        this.uaoSampleFile.delete();
        this.atoSampleFile.delete();
    }

    /**
     * A test that runs the loop zero times
     */
    @Test
    public void loopCoverageZero() {
        this.transactionZero.initTransactionList();

        Assert.assertEquals(-1, this.transactionZero.findNextLogout(0));
    }

    /**
     * A test that runs the loop once
     */
    @Test
    public void loopCoverageOnce() {
        this.transactionOnce.initTransactionList();

        Assert.assertEquals(0, this.transactionOnce.findNextLogout(0));
    }

    /**
     * A test that runs the loop twice
     */
    @Test
    public void loopCoverageTwice() {
        this.transactionTwice.initTransactionList();

        Assert.assertEquals(1, this.transactionTwice.findNextLogout(0));
    }

    /**
     * A test that runs the loop many times
     */
    @Test
    public void loopCoverageMany() {
        this.transactionMany.initTransactionList();

        Assert.assertEquals(2, this.transactionMany.findNextLogout(0));
    }

    /**
     * A test that causes the if statement to be true
     */
    @Test
    public void ifCoverageTrue() {
        this.transactionTrue.initTransactionList();

        Assert.assertEquals(0, this.transactionTrue.findNextLogout(0));
    }

    /**
     * A test that causes the if statement to be false
     */
    @Test
    public void ifCoverageFalse() {
        this.transactionFalse.initTransactionList();

        Assert.assertEquals(0 - 1, this.transactionFalse.findNextLogout(0));
    }
}
