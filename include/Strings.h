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

static const string ENTER_USERNAME;
static const string CREATE_ENTER_USERNAME;
static const string ENTER_ACCOUNT_TYPE;
static const string ENTER_ACCOUNT_BALANCE;
static const string ENTER_CREDIT_AMOUNT;
static const string ENTER_EVENT;
static const string ENTER_PRICE;
static const string ENTER_TICKET_NUMBER;
static const string ENTER_SELLER;
static const string ENTER_BUYER;
static const string ENTER_TRANSFER_AMOUNT;

static const string LOGIN_SUCCESS;
static const string LOGOUT_SUCCESS;
static const string CREATE_SUCCESS;
static const string DELETE_SUCCESS;
static const string ADDCREDIT_SUCCESS;
static const string SELL_SUCCESS;
static const string BUY_SUCCESS;

static const string INVALID_USERNAME;
static const string INVALID_ACCOUNT_TYPE;
static const string INVALID_ACOUNT_BALANCE;
static const string INVALID_CREDIT_AMOUNT;
static const string INVALID_CREDIT_BALANCE;
static const string INVALID_EVENT_TITLE;
static const string INVALID_EVENT_PRICE;
static const string INVALID_TICKET_NUMBER;
static const string INVALID_SELLER;
static const string INVALID_TRANSFER_AMOUNT;

static const string INVALID_COMMAND;
static const string USER_NOT_LOGGED_IN;
static const string USER_ALREADY_LOGGED;

const string INVALID_USERNAME_EXIST = "error: username does not exist";
const string INVALID_ACCOUNT_BUY = "error: user not authorized to buy";
const string INVALID_ACCOUNT_SELL = "error: user not authorized to sell";
const string INVALID_TICKET_REMAINING = "error: not enough tickets remaining";
const string INVALID_TICKET_MAX = "error: a maximum of 4 tickets can be purchased";
const string INVALID_FUNDS = "error: insufficient funds";
const string INVALID_SELLER_BALANCE = "error: seller balance cannot be greater than $999,999";
const string INVALID_EVENT_EXIST = "error: event already exists";
const string INVALID_ADMIN_CREATE = "error: only administrators can create new accounts";
const string INVALID_ADMIN_DELETE = "error: only administrators can delete accounts";
const string INVALID_ADMIN_REFUND = "error: only administrators can make refunds";
const string INVALID_ADMIN_ADD = "error: invalid user privileges";
const string INVALID_DELETE = "error: cannot delete user currently logged in";
const string INVALID_ADD_BALANCE = "error: total balance cannot be greater than $999,999";

#endif /* Strings_H_ */
