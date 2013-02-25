#include "../include/AuxiliaryTransaction.h"

AuxiliaryTransaction::AuxiliaryTransaction(int type, string username,
		double credit, string accountType) : Entry(type) {
	this->username = username;
	this->credit = credit;
	this->accountType = accountType;
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
