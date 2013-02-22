#include <string>

#include "../include/Account.h"

using namespace std;

static const string admin = "AA";
static const string sell  = "SS";
static const string buy   = "BS";
static const string full  = "FS";
static const double maxPrice = 999999.99;

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
