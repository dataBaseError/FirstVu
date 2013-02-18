#include "Ticket.h"

Ticket::Ticket(string event, string username, int ticketNumber, double cost) {
	this->event = event;
	this->username = username;
	this->ticketNumber = ticketNumber;
	this->cost = cost;
}

Ticket::~Ticket() {
	delete event;
	delete username;
	delete ticketNumber;
	delete cost;
}

string Ticket::getEvent() {
    return this->event;
}

void Ticket::setEvent(string event) {
    this->event = event;
}

string Ticket::getUsername() {
    return this->username;
}

void Ticket::setUsername(string userName) {
    this->username = userName;
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

void Ticket::decreaseTicketNumber(int ticketNumber) {
	this->ticketNumber -= ticketNumber;
}
