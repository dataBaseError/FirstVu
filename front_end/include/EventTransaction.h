#ifndef _EVENTTRANSACTION_H_
#define _EVENTTRANSACTION_H_

#include <string>

#include <Account.h>
#include <Entry.h>
#include <Ticket.h>

using namespace std;

/**
 * A class to hold information for a buy or sell transaction.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 *
 */
class EventTransaction : public Entry {

private:
	string eventName;
	string sellName;
	double price;
	int numTickets;

public:

	/**
	 * Constructor for creating an event transaction.
	 *
	 * @param eventName the name of the event.
	 * @param sellName the username of the seller.
	 * @param price the price per ticket.
	 * @param the number of tickets for sale.
	 */
	EventTransaction(int type, string eventName, string sellName,
			double price, int numTickets);

	virtual ~EventTransaction();

	/**
	 * Accessor method for getting the username of the seller.
	 *
	 * @return the seller's username.
	 */
	string getSellName();

	/**
	 * Mutator method for setting the username of the seller.
	 *
	 * @param sellName the seller's username.
	 */
	void setSellName(string sellName);

	/**
	 * Accessor method for getting the name of the event.
	 *
	 * @param the event's name.
	 */
	string getEventName();

	/**
	 * Mutator method for setting the name of the event.
	 *
	 * @param eventName the event's name.
	 */
	void setEventName(string eventName);

	/**
	 * Accessor method for getting the price of an event.
	 *
	 * @return the price of the event.
	 */
	double getPrice();

	/**
	 * Mutator method for setting the price of an event.
	 *
	 * @param price the price of a single ticket for the event.
	 */
	void setPrice(double price);

	/**
	 * Accessor method for getting the number of tickets.
	 *
	 * @return the number of tickets.
	 */
	int getNumTickets();

	/**
	 * Mutator method for setting the number of tickets.
	 *
	 * @param numTickets the number of tickets.
	 */
	void setNumTickets(int numTickets);

    /**
     * @see Entry#getDTFLine()
     */
    virtual string getDTFLine();
};

#endif // _EVENTTRANSACTION_H_
