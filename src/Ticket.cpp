#include "Ticket.h"

String Ticket::getEvent() {
	return this->event;
}

void Ticket::setEvent(String event) {
	this->event = event;
}

String Ticket::getUserName() {
	return this->userName;
}

void Ticket::setUserName(String userName) {
	this->userName = userName;
}

int Ticket::getTicketNumber() {
	return this->ticketNumber;
}

void Ticket::setTicketNumber(int ticketNumber) {
	this->ticketNumber = ticketNumber;
}

double Ticket::getCost() {
	return this->cost;
}

void Ticket::setCost(double cost) {
	this->cost = cost;
}
