#include <Validation.h>

/**
 * A file that contains methods for validating input.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

// match with [0-9]{0,Account::MAX_CREDIT_SIZE}(.[0-9]{2})?
bool validBalance(string balance) {
   stringstream regex;
   regex << "[0-9]{0," << Account::MAX_CREDIT_SIZE << "}(.[0-9]{2})?";

   return Poco::RegularExpression(regex.str()).match(balance);
}

// must be Account.MAX_USERNAME_LENGTH characters
// [A-z], _ and must not contain 'quit'
bool validUsername(string username) {
	if (username.length() <= 0 ||  username.length() >
			Account::MAX_USERNAME_LENGTH) {
		// Username to long
		return false;
	}

	Poco::RegularExpression re1("[A-z_]+");

	if(re1.match(username)) {
		return true;
	}
	//cout << "" << endl;
	// Error invalid username characters
	return false;
}

// must be Ticket.MAX_EVENT_LENGTH characters
// [A-z], _ and must not contain 'quit'
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

// Account.ADMIN or Account.SELL or Account.BUY or Account.FULL and length 2
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

// \d and > 0 and <= Ticket.MAX_TICKET
bool validTicketNumber(int ticketNum) {
	return true;
}

// \d and < Ticket.MAX_PRICE and >= 0.00 and will contain max of 2 decimal points
// must be of size > 0 and =< Ticket.MAX_PRICE_SIZE
// also decide whether to round or truncate
bool validPrice(double price) {
	return true;
	/**
	 * This method is current un-implemented but in the final build will be used
	 * to determine if a price is valid
	 */
}
