#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

using namespace std;

/**
 * A class for storing all the relevant data for each user.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class Account {

private:
    string username;
    string type;
    double balance;

public:
    static const string ADMIN;
    static const string SELL;
    static const string BUY;
    static const string FULL;

    static const double MAX_CREDIT;
    static const int MAX_CREDIT_SIZE;
    static const int MAX_USERNAME_LENGTH;

    /**
     * Constructor for creating a new account.
     *
     * @param username The username for the account
     * @param type The type of account
     * @param balance The balance of the account
     */
    Account(string username, string type, double balance);

    /**
     * Accessor method for retrieving the account type.
     *
     * @return The user's account type.
     */
    string getType();

    /**
     * Mutator method for setting the account type for each account.
     *
     * @param type The user's account new type
     */
    void setType(string type);

    /**
     * Accessor method for retrieving the current balance of the account.
     *
     * @return The user's current balance
     */
    double getBalance();

    /**
     * Mutator method for setting the account balance.
     *
     * @param balance The new balance amount
     */
    void setBalance(double balance);

    /**
     * Accessor method for retrieving the username of the account.
     *
     * @return The user's username
     */
    string getUsername();

    /**
     * Mutator method for setting the username of the account.
     *
     * @param username The user's new username
     */
    void setUsername(string username);

    /**
     * Implemented an equals operator to compare to accounts.
     *
     * @param left The account to the left of the equal signs
     * @param right The account to the right of the equal signs
     * @return Whether or not the accounts are equal
     */
    friend bool operator==(Account left, Account right);
};

#endif // _ACCOUNT_H_
