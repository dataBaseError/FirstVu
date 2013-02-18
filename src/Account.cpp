#include "Account.h"

string Account::getType() {
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

string Account::getUsername() {
	return this->username;
}

void Account::setUsername(String username) {
	this->username = username;
}

void Account::setType(string type) {
	this->type = type;
}

void Account::setUsername(string username) {
	this->username = username;
}
