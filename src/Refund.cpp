#include "../include/Refund.h"

Refund::Refund(int type, string buyName, string sellName, double credit)
: Entry(type){
	this->buyName = buyName;
	this->sellName = sellName;
	this->credit = credit;
}

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
