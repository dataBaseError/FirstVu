#include "Refund.h"

string Refund::getBuyName() {
	return this->buyName;
}

void Refund::setBuyName(string buyName) {
	this->buyName = buyName;
}

string Refund::getSellName() {
	return this->sellName;
}

void Refund::setSellName(string sellName) {
	this->sellName = sellName;
}

double Refund::getCredit() {
	return this->credit;
}

void Refund::setCredit(double credit) {
	this->credit = credit;
}
