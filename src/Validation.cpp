/**
 * A file that contains methods for validating input.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
#include "../include/Validation.h"

// Cast to string
// match with [0-9]+\.[0-9]{2}
// < Account.MAX_CREDIT and >= 0 and has a max of 2 decimal points.
// size of > 0 and =< Account.MAX_CREDIT_SIZE
// decided whether we round or truncate
bool validBalance(double balance) {
   return true;
	/**
	 * This method is current un-implemented but in the final build will be used
	 * to determine if a users balance is valid
	 */
}

// must be Account.MAX_USERNAME_LENGTH characters
// [A-z], _ and must not contain 'quit'
bool validUsername(string username) {
	if (username.length() <= 0 ||  username.length() >
			Account::MAX_USERNAME_LENGTH) {
		// Username to long
		return false;
	}

	//smatch m;
	regex userRegex ("[A-z_]+");

	if (regex_match(username, userRegex)) {
		return true;
	}
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

	smatch m;
	regex EventRegex ("[A-z_]+");

	return regex_search(event, m, EventRegex);
}

// Account.ADMIN or Account.SELL or Account.BUY or Account.FULL and length 2
bool validAccountType(string type) {
	if (type.length() != 2) {
		// Account type too long
		return false;
	}

	smatch m;
	regex AccountRegex (Account::ADMIN + "|" + Account::FULL + "|" +
			Account::SELL + "|" + Account::BUY);

	return regex_search(type, m, AccountRegex);
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
