#include "TicketList.h"

TicketList::TicketList(vector<Ticket> ticketList) {
	this->ticketList= ticketList;
}

TicketList::~TicketList() {
	delete ticketList;
}

vector<Ticket> TicketList::getTicketList() {
    return this->ticketList;
}

void TicketList::setTicketList(vector<Ticket> ticketList) {
    this->ticketList = ticketList;
}

int TicketList::findTicket(string event, string sellName) {
	for(int x = 0; x < this->ticketList.size(); x++)
	{
		if(this->ticketList.at(x).getEvent().compare(event) == 0 &&
		   this->ticketList.at(x).getUsername().compare(sellName) == 0)
		{
			return x;
		}
	}

	return -1;
}
