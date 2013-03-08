/**
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

#ifndef Strings_H_
#define Strings_H_

#include <string>

using namespace std;

// Input Commands
static const string LOGIN = "login";
static const string LOGOUT = "logout";
static const string BUY = "buy";
static const string CREATE = "create";
static const string SELL = "sell";
static const string REFUND = "refund";
static const string ADDCREDIT = "addcredit";
static const string DELETE = "delete";
static const string QUIT = "quit";

// Command Prompts
static const string ENTER_USERNAME = "enter username";
static const string CREATE_ENTER_USERNAME = "enter username to create";
static const string ENTER_ACCOUNT_TYPE = "enter account type";
static const string ENTER_ACCOUT_BALANCE = "enter user account balance";
static const string ENTER_CREDIT_AMOUNT = "enter credit amount";
static const string ENTER_EVENT = "enter event title";
static const string ENTER_PRICE = "enter sale price";
static const string ENTER_TICKET_NUMBER = "enter number of tickets";
static const string ENTER_SELLER = "enter seller's username";
static const string ENTER_BUYER = "enter buyer's username";
static const string ENTER_TRANSFER_AMOUNT = "enter amount to transfer";
static const string CONFIRM_PURCHASE = "confirm purchase: yes or no";

// Informative Messages
static const string TICKET_COST = "cost per ticket: $";
static const string TOTAL_COST = "total cost: $";
static const string CURRENT_BALANCE = "current balance: $";
static const string NEW_BALANCE = "new balance: $";

// Success Messages
static const string LOGIN_SUCCESS = "login successful";
static const string LOGOUT_SUCCESS = "logout successful";
static const string CREATE_SUCCESS = "create successful";
static const string DELETE_SUCCESS = "delete successful";
static const string ADDCREDIT_SUCCESS = "credit added";
static const string SELL_SUCCESS = "tickets added";
static const string BUY_SUCCESS = "purchase successful";
static const string REFUND_SUCCESS = "refund successful";

// Invalid Input Messages
static const string INVALID_USERNAME = "error: invalid username";
static const string INVALID_ACCOUNT_TYPE = "error: invalid account type";
static const string INVALID_ACCOUNT_BALANCE = "error: invalid account balance";
static const string INVALID_CREDIT_AMOUNT = "error: invalid credit amount";
static const string INVALID_EVENT_TITLE = "error: invalid event name";
static const string INVALID_EVENT_PRICE = "error: invalid event price";
static const string INVALID_TICKET_NUMBER = "error: invalid ticket number";
static const string INVALID_SELLER = "error: invalid seller name";
static const string INVALID_TRANSFER_AMOUNT = "error: invalid transfer amount";

// Invalid Command Messages
static const string INVALID_COMMAND = "error: invalid command";
static const string USER_NOT_LOGGED_IN = "error: no users logged in";
static const string USER_ALREADY_LOGGED = "error: user is already logged in";

// Conflicts with User Accounts File or Available Tickets File
static const string INVALID_USERNAME_EXIST = "error: username does not exist";
static const string INVALID_ACCOUNT_BUY = "error: user not authorized to buy";
static const string INVALID_ACCOUNT_SELL = "error: user not authorized to sell";
static const string INVALID_TICKET_REMAINING = "error: not enough tickets remaining";
static const string INVALID_TICKET_MAX = "error: a maximum of 4 tickets can be purchased";
static const string INVALID_FUNDS = "error: insufficient funds";
static const string INVALID_SELLER_BALANCE = "error: seller balance cannot be greater than $999,999";
static const string INVALID_EVENT_EXIST = "error: event already exists";
static const string INVALID_ADMIN_CREATE = "error: only administrators can create new accounts";
static const string INVALID_ADMIN_DELETE = "error: only administrators can delete accounts";
static const string INVALID_ADMIN_REFUND = "error: only administrators can make refunds";
static const string INVALID_ADMIN_ADD = "error: invalid user privileges";
static const string INVALID_DELETE = "error: cannot delete user currently logged in";
static const string INVALID_ADD_BALANCE = "error: total balance cannot be greater than $999,999";

#endif /* Strings_H_ */
