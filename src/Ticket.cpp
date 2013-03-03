#include "../include/Ticket.h"


const double Ticket::MAX_PRICE = 999.99;
const double Ticket::MAX_PRICE_SIZE = 6;
const int Ticket::MAX_TICKET = 100;
const int Ticket::MAX_TICKET_SIZE = 3;
const int Ticket::MAX_EVENT_LENGTH = 19;

Ticket::Ticket(string event, string username, int ticketNumber, double cost) {
	this->event = event;
	this->username = username;
	this->ticketNumber = ticketNumber;
	this->cost = cost;
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

bool operator==(Ticket left, Ticket right) {
    return left.getUsername() == right.getUsername()
            && left.getEvent() == right.getEvent();
}
