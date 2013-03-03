#include <string>

#include "../include/Account.h"

using namespace std;

// ‘static’ may not be used when defining (as opposed to declaring) a static data member [-fpermissive]
const string Account::ADMIN = "AA";
const string Account::SELL  = "SS";
const string Account::BUY   = "BS";
const string Account::FULL  = "FS";

const double Account::MAX_CREDIT = 999999.99;
const int Account::MAX_USERNAME_LENGTH = 15;
const int Account::MAX_EVENT_LENGTH = 19;

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

bool operator==(Account left, Account right) {
    return left.getUsername() == right.getUsername();
}
