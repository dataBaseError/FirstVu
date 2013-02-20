#include "refund.h"

string refund::getBuyName() {
	return this->buyName;
}

void refund::setBuyName(string buyName) {
	this->buyName = buyName;
}

string refund::getSellName() {
	return this->sellName;
}

void refund::setSellName(string sellName) {
	this->sellName = sellName;
}

double refund::getCredit() {
	return this->credit;
}

void refund::setCredit(double credit) {
	this->credit = credit;
}
