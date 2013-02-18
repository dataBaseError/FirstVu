#include "Account.h"

String Account::getType() {
	return this->type;
}

void Account::setType(String type) {
	this->type = type;
}

double Account::getBalance() {
	return this->balance;
}

void Account::setBalance(double balance) {
	this->balance = balance;
}

String Account::getUsername() {
	return this->username;
}

void Account::setUsername(String username) {
	this->username = username;
}
