package testSuite;

import java.io.File;

import main.Transactions;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class CondLoopTest {

    /** 
     * The location of the input files 
     */
    private static String filePrefix = "./tests/full_test/full";

    /**
     * The input Daily Transaction File.
     * To ensure proper coverage, the daily transaction file for testing must contain a variety of transactions.
     * 
     * It's good enough if it contains a refund, buy and logout transaction.
     */
    private static String dtf = filePrefix + ".etf";

    /**
     * The input ticket file
     */
    private static String ato = filePrefix + ".ato";

    /**
     * the input user accounts file
     */
    private static String uao = filePrefix + ".uao";

    /**
     * A sample new User Account file name
     */
    private static String uaoSample = filePrefix + ".usr";

    /**
     * A sample new Tickets file name
     */
    private static String atoSample = filePrefix + ".tic";

    /**
     * Instance of a transaction
     */
    private Transactions transactionMany;

    private Transactions transactionZero;

    /**
     * A sample new user accounts file
     */
    private File uaoSampleFile;

    /**
     * A sample new ticket file
     */
    private File atoSampleFile;

    @Before
    public void setUp() {
        this.transactionMany = new Transactions(dtf, uao, ato, uaoSample, atoSample);
        this.uaoSampleFile = new File(uaoSample);
        this.atoSampleFile = new File(atoSample);

        this.transactionZero = new Transactions(dtf, uao, ato, uaoSample, atoSample);
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

    @Test
    public void loopCoverageZero() {

    }

}
