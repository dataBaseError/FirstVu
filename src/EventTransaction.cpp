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
    throw "To be implemented";
}
