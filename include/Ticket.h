#ifndef _TICKET_H_
#define _TICKET_H_

#include <string>

using namespace std;

/**
 * Class for holding information involving tickets for sale in the program.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class Ticket {

private:
    string event;
    string username;
    int ticketNumber;
    double cost;

public:

    static const double MAX_PRICE;
    static const int MAX_TICKET;
    /**
     * Constructor for making a ticket listing for an event.
     */
    Ticket(string event, string username, int ticketNumber, double cost);

    /**
     * Accessor method for getting the event name.
     *
     * @return Name of the event
     */
	string getEvent();

	/**
	 * Mutator method for the event name.
	 *
	 * @param event Name of the event
	 */
    void setEvent(string event);

    /**
     * Accessor method for getting the seller’s username.
     *
     * @return The username of seller
     */
    string getUsername();

    /**
     * Mutator method for the seller’s username.
     *
     * @param userName The username of seller
     */
    void setUsername(string username);

    /**
     * Accessor method for getting the number of tickets available for the show.
     *
     * @return Number of tickets available
     */
    int getTicketNumber();

    /**
     * Mutator method for number of remaining tickets for sale.
     *
     * @param ticketNumber Number of tickets available
 	 */
    void setTicketNumber(int ticketNumber);

    /**
	 * Decrement the number of tickets for sale for the event.
	 *
	 * @param ticketNumber Number of tickets being purchased
	 */
	void decreaseTicketNumber(int ticketNumber);

    /**
     * Accessor method for getting the cost of the event per ticket.
     *
     * @return Cost of one ticket
     */
    double getCost();

    /**
     * Mutator method for the cost per ticket for the event.
     *
     * @param cost Cost of one ticket
     */
    void setCost(double cost);

    friend bool operator==(Ticket left, Ticket right);
};

#endif // _TICKET_H_
