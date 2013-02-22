#include <string>

#include "../include/Account.h"

using namespace std;

static const string Account::admin = "AA";
static const string Account::sell  = "SS";
static const string Account::buy   = "BS";
static const string Account::full  = "FS";
static const double Account::maxPrice = 999999.99;

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
