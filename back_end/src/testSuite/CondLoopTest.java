package testSuite;

import java.io.File;

import main.Transactions;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class CondLoopTest {

    private static String tests = "./tests/";

    /** 
     * The location of the global user account file and ticket file
     */
    private static String global = tests + "global/";

    /**
     * the input user accounts file
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

    private static String etfs = tests + "loopcoverage/";

    private static String manyEtf = etfs + "many.etf";

    private static String onceEtf = etfs + "one.etf";

    private static String twiceEtf = etfs + "two.etf";

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
        this.transactionZero = new Transactions(dtf, uao, ato, uaoSample, atoSample);
        this.transactionMany = new Transactions(dtf, uao, ato, uaoSample, atoSample);

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

    }

}
