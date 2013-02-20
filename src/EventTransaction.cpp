#include "eventTransactions.h"

string eventTransactions::getSellName() {
	return this->sellName;
}

void eventTransactions::setSellName(string sellName) {
	this->sellName = sellName;
}

string eventTransactions::getEventName() {
	return this->eventName;
}

void eventTransactions::setEventName(string eventName) {
	this->eventName = eventName;
}

double eventTransactions::getPrice() {
	return this->price;
}

void eventTransactions::setPrice(double price) {
	this->price = price;
}

int eventTransactions::getNumTickets() {
	return this->numTickets;
}

void eventTransactions::setNumTickets(int numTickets) {
	this->numTickets = numTickets;
}
