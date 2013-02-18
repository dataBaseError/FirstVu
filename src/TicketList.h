#include <vector>

using namespace std;

/**
 * The array of ticket listings.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class TicketList {

private:
    vector<Ticket> ticketList;

public:
    /**
     * Constructor for creating the list of Tickets.
     */
    TicketList(vector<Ticket> ticketList);

    /**
     * De-constructor for deleting a list of tickets.
     */
    ~TicketList();

    /**
     * Accessor method for getting the list of tickets.
     *
     * @return List of available tickets
     */
    vector<Ticket> getTicketList();

    /**
     * Mutator method for setting a list of tickets.
     *
     * @param ticketList List of available tickets
     */
    void setTicketList(vector<Ticket> ticketList);

    /**
     * Find the index of the ticket listing given the event name and seller’s name.
     *
     * @param event Name of the event
     * @param sellName Username of seller
     * @return Index of ticket
     */
    int findTicket(string event, string sellName);
};
