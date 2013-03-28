/**
 * Contains the main method.
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class Backend {

    /**
     * Runs the backend.
     * Any errors will appear in the standard error stream.
     * 
     * @param args
     *      <ul>
     *          <li>args[0]: current user account file</li>
     *          <li>args[1]: current ticket file</li>
     *          <li>args[2]: current daily transaction file</li>
     *          <li>args[3]: new user account file</li>
     *          <li>args[4]: new ticket file</li>
     *      </ul>
     */
    public static void main(final String[] args) {
    	Transactions activityLog = new Transactions(args[2], args[0], args[1], args[3], args[4]);
    	
    	if(!activityLog.initTransactionList())
    	{
    		// Error reading input files.
    	}
    	
    	
    	
    }

}