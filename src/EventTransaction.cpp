#include "EventTransaction.h"

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
