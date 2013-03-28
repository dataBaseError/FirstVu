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
        if (args.length > 4) {
            final Transactions activityLog = new Transactions(args[2], args[0], args[1], args[3], args[4]);
            int nextLogout = 0;
            int previousLogout = 0;

            if (!activityLog.initTransactionList()) {
                // Error reading input files.
            }

            while (nextLogout != -1) {

                nextLogout = activityLog.findNextLogout(nextLogout);
                activityLog.login(nextLogout);

                for (int i = previousLogout; i < nextLogout; i++) {
                    final Entry currentTransaction = activityLog.getTransactions().get(i);

                    switch (currentTransaction.getTransactionType()) {
                        case AuxiliaryTransaction.LOGOUT:
                            activityLog.logout();
                            break;
                        case AuxiliaryTransaction.CREATE:
                            activityLog.create((AuxiliaryTransaction) currentTransaction);
                            break;
                        case AuxiliaryTransaction.DELETE:
                            activityLog.delete((AuxiliaryTransaction) currentTransaction);
                            break;
                        case AuxiliaryTransaction.ADDCREDIT:
                            activityLog.addcredit((AuxiliaryTransaction) currentTransaction);
                            break;
                        case EventTransaction.SELL:
                            activityLog.sell((EventTransaction) currentTransaction);
                            break;
                        case EventTransaction.BUY:
                            activityLog.buy((EventTransaction) currentTransaction);
                            break;
                        case Refund.REFUND:
                            activityLog.refund((Refund) currentTransaction);
                            break;
                    }
                }

                previousLogout = nextLogout;
            }

        }
    }
}