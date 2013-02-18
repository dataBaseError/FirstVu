#include "TicketList.h"

vector<Ticket> TicketList::getTicketList() {
    return this->ticketList;
}

void TicketList::setTicketList(vector<Ticket> ticketList) {
    this->ticketList = ticketList;
}
