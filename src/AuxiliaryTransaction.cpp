#include "AuxiliaryTransaction.h"

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

string AuxiliaryTransaction::getType() {
	return this->type;
}

void AuxiliaryTransaction::setType(string type) {
	this->type = type;
}
