#include <string>
#include <vector>

#include "Entry.h"
#include "EventTransaction.h"
#include "AuxiliaryTransaction.h"
#include "Refund.h"
#include "FileIO.h"

using namespace std;

/**
 * A class that defines all of the legal transactions for the user to make.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 *
 */
class Transaction {

private:
    FileIO* fileIO;
	vector<Entry>* transaction;
	int currentUser;

	/**
	 * Initialization for a new session.
	 *
	 * @return whether the transaction successfully initialized.
	 */
	bool initTransaction();

public:
	static const double maxAddCredit;

	/**
	 * The constructor for starting sessions of transactions.
	 *
	 * @param accountPath the path of the current user accounts file
	 * @param availTicketPath the path of the available tickets file
	 */
	Transaction(string accountPath, string availTicketPath);

	/**
	 * The deconstructor to delete the transaction session handler.
	 */
	~Transaction();

	/**
	 * The initial transaction for starting a user session allowing for all
	 * other transactions to be done.
	 *
	 * @param username the username of the user logging in.
	 */
	bool login(string username);

	/**
	 * The transaction that ends a session. No other transactions will be
	 * accepted until a user logs in again.
	 */
	bool logout();

	bool buy(string event, int numTickets, string sellName);

	bool sell(string event, double salePrice, int availTicket);

	bool create(string newUser, string accountType, double accountBalance);

	bool removeUser(string username);

	bool addcredit(double amount);

	bool addcredit(string username, double amount);

	bool refund(string buyName, string sellName, double amount);

	FileIO* getFileIO();

	int Transaction::getCurrentUser();
};
