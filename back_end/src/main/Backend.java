package main;
/**
 * This program is designed to read in 3 files: the user accounts file, the
 * available tickets file, and the daily transaction file. The transactions
 * found in the daily transaction file will be executed sequentially starting at
 * the top of the list. The execution of these transactions will apply changes
 * to the user accounts list and available tickets list. Error messages will be
 * displayed for transactions that are invalid. Once every valid transaction has
 * been executed the updated user accounts list and available tickets list will
 * be written to the location provided (as arguments 4 and 5 respectively). 
 * 
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
public class Backend {

    /**
     * Runs the backend.
     * Any errors will appear in the standard output stream.
     * 
     * @param args
     *      <ul>
     *          <li>args[0]: current daily transaction file</li>
     *          <li>args[1]: current ticket file</li>
     *          <li>args[2]: current user account file</li>
     *          <li>args[3]: new user account file</li>
     *          <li>args[4]: new ticket file</li>
     *      </ul>
     */
    public static void main(final String[] args) {
        if (args.length > 4) {
        	
        	// Initialize 
            final Transactions activityLog = new Transactions(args[0], args[1],
            		args[2], args[3], args[4]);
            int nextLogout = 0;
            int previousLogout = 0;

            if (activityLog.initTransactionList()) {

            	// Parse through transactions and apply them
            	nextLogout = activityLog.findNextLogout(nextLogout);
            	
            	for (int j = 0; j < activityLog.getTransactions().size(); j++) {
	                
	                activityLog.login(nextLogout);
	                
	                for (int i = previousLogout; i <= nextLogout; i++) {
	                    final Entry currentTransaction = activityLog
	                    		.getTransactions().get(i);
	
	                    switch (currentTransaction.getTransactionType()) {
	                        case AuxiliaryTransaction.LOGOUT:
	                            activityLog.logout();
	                            break;
	                        case AuxiliaryTransaction.CREATE:
	                            activityLog.create((AuxiliaryTransaction)
	                            		currentTransaction);
	                            break;
	                        case AuxiliaryTransaction.DELETE:
	                            activityLog.delete((AuxiliaryTransaction)
	                            		currentTransaction);
	                            break;
	                        case AuxiliaryTransaction.ADDCREDIT:
	                            activityLog.addcredit((AuxiliaryTransaction)
	                            		currentTransaction);
	                            break;
	                        case EventTransaction.SELL:
	                        	activityLog.sell((EventTransaction)
	                            		currentTransaction);
	                            break;
	                        case EventTransaction.BUY:
	                            activityLog.buy((EventTransaction)
	                            		currentTransaction);
	                            break;
	                        case Refund.REFUND:
	                            activityLog.refund((Refund) currentTransaction);
	                            break;
	                    }
	                }
	                
	                previousLogout = nextLogout;
	                nextLogout = activityLog.findNextLogout(nextLogout+1);
	            }
	
	            activityLog.endSession();
            }
        }
    }
}