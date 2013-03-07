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

static const string LOGIN = "login";
static const string LOGOUT = "logout";
static const string BUY = "buy";
static const string CREATE = "create";
static const string SELL = "sell";
static const string REFUND = "refund";
static const string ADDCREDIT = "addcredit";
static const string DELETE = "delete";
static const string QUIT = "quit";

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

static const string LOGIN_SUCCESS = "login successful";
static const string LOGOUT_SUCCESS = "logout successful";
static const string CREATE_SUCCESS = "create_successful";
static const string DELETE_SUCCESS = "delete_successful";
static const string ADDCREDIT_SUCCESS = "credit added";
static const string SELL_SUCCESS = "tickets added";
static const string BUY_SUCCESS = "purchase successful";
static const string REFUND_SUCCESS = "refund successful";

static const string INVALID_USERNAME = "error: invalid username";
static const string INVALID_ACCOUNT_TYPE = "error: invalid account type";
static const string INVALID_ACCOUNT_BALANCE = "error: invalid account balance";
static const string INVALID_CREDIT_AMOUNT = "error: invalid credit amount";
static const string INVALID_EVENT_TITLE = "error: invalid event name";
static const string INVALID_EVENT_PRICE = "error: invalid event price";
static const string INVALID_TICKET_NUMBER = "error: invalid ticket number";
static const string INVALID_SELLER = "error: invalid seller name";
static const string INVALID_TRANSFER_AMOUNT = "error: invalid transfer amount";

static const string INVALID_COMMAND = "error: invalid command";
static const string USER_NOT_LOGGED_IN = "error: no users logged in";
static const string USER_ALREADY_LOGGED = "error: user is already logged in";

#endif /* Strings_H_ */
