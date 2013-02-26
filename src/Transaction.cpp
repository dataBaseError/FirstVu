#include "../include/Transaction.h"

const double Transaction::maxAddCredit = 1000.00;

Transaction::Transaction(string accountPath, string availTicketPath) {
	this->currentUser = -1;
	this->fileIO = new FileIO();
	this->transaction = new vector<Entry>();
}

Transaction::~Transaction() {
	delete transaction;
    delete fileIO;
}

bool Transaction::login(string username) {
	// Check if transaction list is empty
	if (currentUser == -1) {

		// Read in uao and ato files
		if (this->fileIO->initialize()) {

			currentUser = this->fileIO->findUser(username);
			if (currentUser == -1) {
				// Invalid user
				return false;
			}

			// Initialize transaction list
			this->transaction = new vector<Entry>();

			return true;
		}
	}

    return false;
}

bool Transaction::logout() {
	// Write to daily transaction file
	if (this->fileIO->writeTransaction(this->transaction)) {
	    // Apparently, committing suicide is legal behaviour
	    //~Transaction();
		delete transaction;
		//delete this;
	}

	return false;
}

bool Transaction::buy(string event, int numTickets, string sellName) {
	// verify valid input
	// buyer's name, event, and seller's name must exist
		// assume buyer name is correct
	// seller must be selling tickets for event
	// there must be enough tickets available
	// maximum of 4 tickets can be purchased, minimum of 1
	// buyer must have sufficient funds
	// seller's credit must not exceed maximum after transaction
	// buyer must have buy privileges
		// seller can buy back their own tickets

	if (currentUser == -1) {
		// No user logged in
		return false;
	}


	if(this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::sell) == 0) {

		// User does not have buy privileges
		return false;
	}

	if (numTickets <= 0) {

		// Not enough tickets purchased
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::admin) != 0 && numTickets > 4) {

		// User cannot buy more than 4 tickets
		return false;
	}

	/* if ((this->fileIO->getAccountList()->at(buyer).getType()
			.compare(Account::sell) != 0) && ((this->fileIO->getAccountList()
			->at(buyer).getType().compare(Account::admin) != 0 &&
			numTickets <= 4 && numTickets > 0) ||
			this->fileIO->getAccountList()->at(buyer).getType()
			.compare(Account::admin) == 0)) {
	*/

	int seller = this->fileIO->findUser(sellName);

	if (seller == 0) {

		// Seller does not exist
		return false;
	}

	int ticket = this->fileIO->findEvent(event, sellName);

	if (ticket == 0) {

		// Event does not exist
		return false;
	}
	double cost = this->fileIO->getTicketList()->at(ticket).getCost()
			* numTickets;

	if (this->fileIO->getAccountList()->at(currentUser).getBalance()
			< cost) {

		// User has insufficient funds
		return false;
	}

	if ((this->fileIO->getAccountList()->at(currentUser).getBalance()
			+ cost) > Account::maxCredit) {

		// Seller's funds will exceed max price
		return false;
	}

	// buy start
	// remove cost from buyer's account
	// add cost to seller's account
	// remove number of tickets from event
		// delete event if it no longer has tickets
	// write to daily transaction file

	this->fileIO->getAccountList()->at(currentUser).setBalance(
			this->fileIO->getAccountList()->at(currentUser).getBalance()
			- cost);

	this->fileIO->getAccountList()->at(seller).setBalance(
			this->fileIO->getAccountList()->at(seller).getBalance()
			+ cost);

	this->fileIO->getTicketList()->at(ticket).decreaseTicketNumber
			(numTickets);

	if (this->fileIO->getTicketList()->at(ticket).getTicketNumber()
			== 0) {
		// delete ticket
		this->fileIO->getTicketList()->erase(this->fileIO
				->getTicketList()->begin() + (ticket - 1),
				this->fileIO->getTicketList()->begin() + ticket);
	}

	double ticketCost = this->fileIO->getTicketList()->at(ticket).getCost();
	// add transaction to transaction list
	EventTransaction buy (Entry::buy, event, sellName, ticketCost, numTickets);

	this->transaction->push_back(buy);

    return true;
}

bool Transaction::sell(string event, double salePrice, int availTicket) {
	//sellName and must not be null
		//sell must exist, must have sell privilege,
		//must not have an event with the given event name already listed
	//salePrice cant be greater than 999.99 and greater than 0
	//availTicket must be less than 100 and greater than 0


	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	string sellName = this->fileIO->getAccountList()->at(currentUser).getUsername();

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::buy) == 0){
		// Invalid privileges
		return false;
	}
	if (availTicket <= 0 || availTicket > Ticket::maxTicket) {
		// Invalid number of Tickets
		return false;
	}

	if (salePrice < 0 || salePrice > Ticket::maxPrice) {
		// Invalid Ticket Price
		return false;
	}

	if (this->fileIO->findEvent(event, sellName) >= 0) {
		// Event already exists
		return false;
	}

	// Sell start:
	// Create event
	// Add to available ticket file
	// Create transaction
	// Add to daily transaction file

	Ticket newEvent (event, sellName, availTicket, salePrice);

	this->fileIO->getTicketList()->push_back(newEvent);

	//this->fileIO->updateAvailTickets();

	EventTransaction sell (Entry::sell, event, sellName, salePrice, availTicket);

	this->transaction->push_back(sell);

	return true;
}

bool Transaction::create(string newUser, string accountType,
		double accountBalance) {

	// newUser does not already exist
	// valid accountType
	// accountBalance between 0 and maxCredit

	if (currentUser == -1) {
		// No user logged in
		return false;
	}

	if (accountType.compare(Account::buy) != 0 &&
			accountType.compare(Account::sell) != 0 &&
			accountType.compare(Account::full) != 0 &&
			accountType.compare(Account::admin) != 0) {

		// Invalid account type
		return false;
	}

	if (accountBalance < 0 || accountBalance > Account::maxCredit) {

		// Invalid credit
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::admin) != 0) {
		// Invalid user privileges
		return false;
	}

	Account newAccount(newUser, accountType, accountBalance);
	this->fileIO->getAccountList()->push_back(newAccount);

	return true;
}

bool Transaction::removeUser(string username) {
    // check if user is logged in
	// check if user is admin
	// check if user to be deleted exists
	// check that user to be deleted is not logged in

	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::admin) != 0) {
		// Invalid user privileges
		return false;
	}

	int user = this->fileIO->findUser(username);
	if (user == -1) {
		// User does not exist
		return false;
	}

	if (currentUser == user) {
		// Cannot delete self
		return false;
	}

	string type = this->fileIO->getAccountList()->at(user).getType();
	double balance = this->fileIO->getAccountList()->at(user).getBalance();

	// delete
	this->fileIO->getAccountList()->erase(this->fileIO
					->getAccountList()->begin() + (user - 1),
					this->fileIO->getAccountList()->begin() + user);

	AuxiliaryTransaction remove (Entry::del, username, balance, type);
	this->transaction->push_back(remove);

	return true;
}

bool Transaction::addcredit(double amount) {
	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	if (amount > Transaction::maxAddCredit) {
		// Invalid credit amount
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(currentUser)
			.getBalance() + amount;

	if (newBalance > Account::maxCredit) {
		// Will exceed maximum credit balance
		return false;
	}

	this->fileIO->getAccountList()->at(currentUser).setBalance(newBalance);

	string username = this->fileIO->getAccountList()->at(currentUser).getUsername();
	string type = this->fileIO->getAccountList()->at(currentUser).getType();
	AuxiliaryTransaction add (Entry::addcredit, username, newBalance, type);
	this->transaction->push_back(add);

	return true;
}

bool Transaction::addcredit(string username, double amount) {
	// check if user is logged in
	// check if current user is admin
		// check if user exists
	// check if amount is valid
	// check if new balance will be over the max

	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	int user = this->fileIO->findUser(username);
	if (user == -1) {
		// User does not exist
		return false;
	}

	if (amount > Transaction::maxAddCredit) {
		// Invalid credit amount
		return false;
	}


	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::admin) != 0) {
		// user is not admin
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(user).getBalance() + amount;
	if (newBalance > Account::maxCredit) {
		// Will exceed maximum credit balance
		return false;
	}

	// add amount to user
	// add transaction to transaction list
	this->fileIO->getAccountList()->at(user).setBalance(newBalance);

	string type = this->fileIO->getAccountList()->at(user).getType();
	AuxiliaryTransaction add (Entry::addcredit, username, newBalance, type);
	this->transaction->push_back(add);
    return true;
}

bool Transaction::refund(string buyName, string sellName, double amount) {
    throw "Not yet implemented";
}

bool Transaction::initTransaction() {
    throw "Not yet implemented";
}

FileIO* Transaction::getFileIO() {
	return this->fileIO;
}
