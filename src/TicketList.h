#include <vector>

using namespace std;

class TicketList {

private:
    vector<Ticket> ticketList;

public:
    vector<Ticket> getTicketList();

    void setTicketList(vector<Ticket> ticketList);
};
