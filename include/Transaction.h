#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <cstring>
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
	 * @param accountPath the path of the current user accounts file.
	 * @param availTicketPath the path of the available tickets file.
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
	 *
	 * @return whether the logout was successful.
	 */
	bool logout();

	/**
	 * The transaction for buy tickets for an event. The user must have buy
	 * privileges.
	 *
	 * @param event the name of the event.
	 * @param numTickets the number of tickets to purchase.
	 * @param sellName the seller's username.
	 * @return whether the buy was successful.
	 */
	bool buy(string event, int numTickets, string sellName);

	/**
	 * The transaction for posting new tickets to be sold for an event.
	 *
	 * @param event the name of the event.
	 * @param salePrice the price per ticket.
	 * @param availTicket the number of tickets for sale.
	 * @return whether the sell was successful.
	 */
	bool sell(string event, double salePrice, int availTicket);

	/**
	 * The transaction for creating a new user for the system.
	 *
	 * @param newUser the name of the new user.
	 * @param accountType the type of account for the new user.
	 * @param accountBalance the initial account balance for the new user.
	 * @return whether the create was successful.
	 */
	bool create(string newUser, string accountType, double accountBalance);

	/**
	 * The transaction for deleting a user from the system.
	 *
	 * @param username the username of the user to be deleted.
	 * @return whether the removal was successful.
	 */
	bool removeUser(string username);

	/**
	 * The transaction for adding credit to a user’s account. Buy standard and
	 * full standard will use this method since they can only add credit to
	 * their own account.
	 *
	 * @param amount the amount to add to the account.
	 * @return whether the addition of credit was successful.
	 */
	bool addcredit(double amount);

	/**
	 * The transaction for adding credit to a user’s account. This method is
	 * only for use by a user with administrative privileges.
	 *
	 * @param username the username who the addition of credit will go to.
	 * @param amount the amount to add to the account.
	 * @return whether the addition of credit was successful.
	 */
	bool addcredit(string username, double amount);

	/**
	 * The transaction for refunding money from one user to another user.
	 *
	 * @param buyName the username of the buyer who is receiving the refund.
	 * @param sellName the username of the seller who is giving the refund.
	 * @param amount the of money being refunded.
	 * @return whether the refund was successful.
	 */
	bool refund(string buyName, string sellName, double amount);

	/**
	 * Accessor method for fileIO.
	 *
	 * @return the fileIO object.
	 */
	FileIO* getFileIO();

	/**
	 * Accessor method for the current user’s id.
	 *
	 * @return the current user's index that is logged in.
	 */
	int getCurrentUser();

	bool isAdmin();

	bool isLoggedIn();
};
