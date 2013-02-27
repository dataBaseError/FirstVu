#include <string>

#include "Entry.h"

using namespace std;

/**
 * A class to hold information for a refund transaction.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class Refund : public Entry {

private:
	string buyName;
	string sellName;
	double credit;

public:

	/**
	 * Constructor to create a refund transaction.
	 *
	 * @param buyName the buyer's username.
	 * @param sellName the seller's username.
	 * @param credit the amount of credit involved in the refund.
	 */
	Refund(int type, string buyName, string sellName, double credit);

	/**
	 * Accessor method for getting the username of the buyer.
	 *
	 * @return the buyer's username.
	 */
	string getBuyName();

	/**
	 * Mutator method for setting the username of the buyer.
	 *
	 * @param buyName the new buyer's username.
	 */
	void setBuyName(string buyName);

	/**
	 * Accessor method for getting the username of the seller.
	 *
	 * @return the seller's username.
	 */
	string getSellName();

	/**
	 * Mutator method for setting the username of the seller.
	 *
	 * @param sellName the new seller's username.
	 */
	void setSellName(string sellName);

	/**
	 * Accessor method for getting the amount of credit to be refunded.
	 *
	 * @return the number of credits transfered as part of the refund
	 */
	double getCredit();

	/**
	 * Mutator method for setting the amount of credit to be refunded.
	 *
	 * @param credit the new amount of credit transfered as part of the refund
	 */
	void setCredit(double credit);
};
