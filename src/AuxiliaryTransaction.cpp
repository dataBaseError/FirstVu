#include "../include/AuxiliaryTransaction.h"

AuxiliaryTransaction::AuxiliaryTransaction(int type, string username,
		double credit, string accountType) : Entry(type) {
	this->username = username;
	this->credit = credit;
	this->accountType = accountType;
}

AuxiliaryTransaction::~AuxiliaryTransaction() {

}

string AuxiliaryTransaction::getUsername() {
	return this->username;
}

void AuxiliaryTransaction::setUsername(string username) {
	this->username = username;
}

double AuxiliaryTransaction::getCredit() {
	return this->credit;
}

void AuxiliaryTransaction::setCredit(double credit) {
	this->credit = credit;
}

string AuxiliaryTransaction::getAccountType() {
	return this->accountType;
}

void AuxiliaryTransaction::setAccountType(string accountType) {
	this->accountType = accountType;
}

string AuxiliaryTransaction::getDTFLine() {
    stringstream buffer;

    buffer << setfill('0') << setw(2) << getTransactionType() << " ";
    buffer << setfill(' ') << setw(Account::MAX_USERNAME_LENGTH) << getUsername() << " ";
    buffer << getAccountType() << " ";
    buffer << setfill('0') << setw(Account::MAX_CREDIT_SIZE) << setprecision(2) << getCredit();
    buffer << endl;

    return buffer.str();
}
