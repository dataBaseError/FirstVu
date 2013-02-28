#include <string>

using namespace std;

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {

private:
    string username;
    string type;
    double balance;

public:
    static const string admin;
    static const string sell;
    static const string buy;
    static const string full;
    static const double maxCredit;

    Account(string username, string type, double balance);

    string getType();

    void setType(string type);

    double getBalance();

    void setBalance(double balance);

    string getUsername();

    void setUsername(string username);
};

#endif
