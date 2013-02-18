#include "TicketList.h"

Vector<Ticket> TicketList::getTicketList() {
	return this->ticketList;
}

void TicketList::setTicketList(Vector<Ticket> ticketList) {
	this->ticketList = ticketList;
}
