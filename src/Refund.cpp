#include "../include/Refund.h"

Refund::Refund(int type, string buyName, string sellName, double credit)
: Entry(type){
	this->buyName = buyName;
	this->sellName = sellName;
	this->credit = credit;
}

Refund::~Refund() {

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

string Refund::getDTFLine() {
    stringstream buffer;

    char amount[Account::MAX_CREDIT_SIZE];
    char* format;
    sprintf(format, "%s%d%s", "%", Account::MAX_CREDIT_SIZE, ".2f");
    sprintf(amount, format, getCredit());

    buffer << right << setfill('0') << setw(2) << getTransactionType() << " ";
    buffer << left << setw(Account::MAX_USERNAME_LENGTH) << getBuyName() << " ";
    buffer << left << setw(Account::MAX_USERNAME_LENGTH) << getSellName() << " ";
    buffer << amount << endl;

    return buffer.str();
}
