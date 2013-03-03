#include "../include/EventTransaction.h"

EventTransaction::EventTransaction(int type, string eventName, string sellName, double price, int numTickets)
: Entry(type) {
	this->eventName = eventName;
	this->sellName = sellName;
	this->price = price;
	this-> numTickets = numTickets;
}

EventTransaction::~EventTransaction() {

}

string EventTransaction::getSellName() {
	return this->sellName;
}

void EventTransaction::setSellName(string sellName) {
	this->sellName = sellName;
}

string EventTransaction::getEventName() {
	return this->eventName;
}

void EventTransaction::setEventName(string eventName) {
	this->eventName = eventName;
}

double EventTransaction::getPrice() {
	return this->price;
}

void EventTransaction::setPrice(double price) {
	this->price = price;
}

int EventTransaction::getNumTickets() {
	return this->numTickets;
}

void EventTransaction::setNumTickets(int numTickets) {
	this->numTickets = numTickets;
}

string EventTransaction::getDTFLine() {
    stringstream buffer;

    char price[Ticket::MAX_PRICE_SIZE];
    char format[5];
    sprintf(format, "%%%d.2f", Ticket::MAX_PRICE_SIZE);
    sprintf(price, format, getPrice());

    buffer << right << setfill('0') << setw(2) << getTransactionType() << " ";
    buffer << left << setfill(' ') << setw(Ticket::MAX_EVENT_LENGTH) << getEventName() << " ";
    buffer << left << setfill(' ') << setw(Account::MAX_USERNAME_LENGTH) << getSellName() << " ";
    buffer << right << setfill('0') << setw(Ticket::MAX_TICKET_SIZE) << " ";
    buffer << price << endl;


    return buffer.str();
}
