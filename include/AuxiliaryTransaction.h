#include <string>

#include "Entry.h"

using namespace std;

/**
 * A class to hold information for a create, delete, addcredit, or end transaction.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class AuxiliaryTransaction : public Entry {

private:
	string username;
	double credit;
	string accountType;

public:

	/**
	 * Constructor for creating a new transaction.
	 *
	 * @param username the username involved in the transaction.
	 * @param credit the credit involved in the transaction.
	 * @param type the type of user involved in the transaction.
	 */
	AuxiliaryTransaction(int type, string username, double credit,
			string accountType);

	/**
	 * Accessor method for getting the username.
	 *
	 * @return the username of the user involved in the transaction
	 */
	string getUsername();

	/**
	 * Mutator method for setting the username.
	 *
	 * @param username the new username of the user involved in the transaction.
	 */
	void setUsername(string username);

	/**
	 * Accessor method for getting the credit amount associated with the transaction.
	 *
	 * @return the amount of credit involved in the transaction.
	 */
	double getCredit();

	/**
	 * Mutator method for setting the amount of credit.
	 *
	 * @param credit the amount of credit involved in the transaction.
	 */
	void setCredit(double credit);

	/**
	 * Accessor method for getting the user account type.
	 *
	 * @return the type of user that is involved in the transaction
	 */
	string getAccountType();

	/**
	 * Mutator method for setting the account type.
	 *
	 * @param type the type of user that is involved in the transaction
	 */
	void setAccountType(string type);
};
