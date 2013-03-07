/**
 * A file that contains static methods for validating input from the user.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <string>


using namespace std;

/**
 * Validate the entered balance.
 *
 * @param balance The entered balance
 * @return Whether the entered balance is a valid balance.
 */
bool validBalance(double balance);

/**
 * Validate the username.
 *
 * @param username The entered username
 * @return Whether the username was valid.
 */
bool validUsername(string username);

/**
 * Validate the event's name.
 *
 * @param event The entered event.
 * @return Whether the event's name was valid.
 */
bool validEventName(string event);

/**
 * Validate the account type.
 *
 * @param type The entered account type.
 * @return Whether the account type was valid.
 */
bool validAccountType(string type);

bool validTicketNumber(int ticketNum);

/**
 * Validate the price.
 *
 * @param price The entered price of an event.
 * @return Whether the price was valid.
 */
bool validPrice(double price);

#endif /* VALIDATION_H_ */
