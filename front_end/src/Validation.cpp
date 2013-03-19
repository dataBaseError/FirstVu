/**
 * A file that contains methods for validating input.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

#include <Validation.h>

/**
 *  A valid balance will match with only be digits and be a max size of
 *  Account::Max_CREDIT_SIZE
 *  Given by the regular expression:
 *  	[1-9]{0,Account::MAX_CREDIT_SIZE-3}(.[0-9]{2})?
 */
bool validBalance(string balance) {
   stringstream regex;
   regex << "[0-9]{1," << Account::MAX_CREDIT_SIZE - 3 << "}(.[0-9]{2})?";

   return Poco::RegularExpression(regex.str()).match(balance);
}

/**
 * A valid price will match will be only numbers and less than Ticket.MAX_PRICE
 * and less than or equal to 0.00 and will contain max of 2 decimal points.
 * Also, the size of the price must be greater than 0 and less than or equal to
 * Ticket.MAX_PRICE_SIZE.
 *
 * Given by the regular expression:
 * 		[0-9]{1,Ticket::MAX_PRICE_SIZE - 3}(.[0-9]{2})?
 */
bool validPrice(string price) {
    stringstream regex;
    regex << "[0-9]{1," << Ticket::MAX_PRICE_SIZE - 3 << "}(.[0-9]{2})?";

    return Poco::RegularExpression(regex.str()).match(price);
}

/**
 * A valid username must contain only characters A-Z upper or lower case
 * or underscores. Also the username must not be 'quit' and finally, the
 * username must be great then 0 characters long and less than or equal to
 * Account::MAX_USERNAME_LENGTH
 *
 * Given by the regular expression:
 * 		[A-z_]+
 */
bool validUsername(string username) {
	if (username.length() <= 0 ||  username.length() >
			Account::MAX_USERNAME_LENGTH) {
		// Username to long
		return false;
	}

	Poco::RegularExpression re1("[A-z_]+");

	if(re1.match(username) && username.compare("quit") != 0) {
		return true;
	}
	//cout << "" << endl;
	// Error invalid username characters
	return false;
}

/**
 * A valid event name must contain only characters A-Z upper or lower case
 * or underscores. Also the event name must not be 'quit' and finally, the
 * event name must be great then 0 characters long and less than or equal to
 * Ticket.MAX_EVENT_LENGTH
 *
 * Given by the regular expression:
 * 		[A-z_]+
 */
bool validEventName(string event) {
	if (event.length() <= 0 || event.length() >
			Ticket::MAX_EVENT_LENGTH) {
		// Event name to long
		return false;
	}

	Poco::RegularExpression re1("[A-z_]+");

	if(re1.match(event)) {
		// Valid username
		return true;
	}

	// Invalid username
	return false;
}

/**
 * A valid account type can only be one of:
 * 		Account::ADMIN
 * 		Account::FULL
 * 		Account::SELL
 * 		Account::BUY
 *
 * The account type must also be 2 characters long.
 */
bool validAccountType(string type) {
	if (type.length() != 2) {
		// Account type too long
		return false;
	}

	if (type.compare(Account::ADMIN) == 0 || type.compare(Account::FULL) == 0 ||
			type.compare(Account::SELL) == 0 || type.compare(Account::BUY) == 0) {
		// Valid type
		return true;
	}

	// Invalid user account type
	return false;
}

/**
 * A valid ticket number must be greater than 0 and less than or equal to
 * Ticket::MAX_TICKET.
 */
bool validTicketNumber(int ticketNum) {
	if(ticketNum > 0 && ticketNum <= Ticket::MAX_TICKET) {
	    return true;
	}

	return false;
}
