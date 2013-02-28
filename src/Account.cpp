#include <string>

#include "../include/Account.h"

using namespace std;

// ‘static’ may not be used when defining (as opposed to declaring) a static data member [-fpermissive]
const string Account::admin = "AA";
const string Account::sell  = "SS";
const string Account::buy   = "BS";
const string Account::full  = "FS";
const double Account::maxCredit = 999999.99;

Account::Account(string username, string type, double balance) {
	this->username = username;
	this->type = type;
	this->balance = balance;
}

string Account::getType() {
    return this->type;
}

void Account::setType(string type) {
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

void Account::setUsername(string username) {
    this->username = username;
}
