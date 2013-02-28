#include "../include/Transaction.h"

const double Transaction::maxAddCredit = 1000.00;

Transaction::Transaction(string accountPath, string availTicketPath) {
	this->currentUser = 0;
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
		transaction->clear();
		//delete this;
		this->currentUser = -1;
	}
	else {
		// Error writing to transaction file
		return false;
	}

	return false;
}

bool Transaction::buy(string event, int numTickets, string sellName) {

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

	// Buy Start
	this->fileIO->getAccountList()->at(currentUser).setBalance(
			this->fileIO->getAccountList()->at(currentUser).getBalance()
			- cost);

	this->fileIO->getAccountList()->at(seller).setBalance(
			this->fileIO->getAccountList()->at(seller).getBalance()
			+ cost);

	this->fileIO->getTicketList()->at(ticket).decreaseTicketNumber
			(numTickets);

	if (this->fileIO->getTicketList()->at(ticket).getTicketNumber() == 0) {
		// Delete ticket
		this->fileIO->getTicketList()->erase(this->fileIO
				->getTicketList()->begin() + (ticket - 1),
				this->fileIO->getTicketList()->begin() + ticket);
	}

	double ticketCost = this->fileIO->getTicketList()->at(ticket).getCost();

	// Add transaction to transaction list
	EventTransaction buy (Entry::buy, event, sellName, ticketCost, numTickets);

	this->transaction->push_back(buy);

    return true;
}

bool Transaction::sell(string event, double salePrice, int availTicket) {

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

	// Sell start
	Ticket newEvent (event, sellName, availTicket, salePrice);

	this->fileIO->getTicketList()->push_back(newEvent);

	EventTransaction sell (Entry::sell, event, sellName, salePrice, availTicket);
	this->transaction->push_back(sell);

	return true;
}

bool Transaction::create(string newUser, string accountType,
		double accountBalance) {

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

	// Create Start
	Account newAccount(newUser, accountType, accountBalance);
	this->fileIO->getAccountList()->push_back(newAccount);

	return true;
}

bool Transaction::removeUser(string username) {

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

	// Delete Start
	string type = this->fileIO->getAccountList()->at(user).getType();
	double balance = this->fileIO->getAccountList()->at(user).getBalance();

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

	// AddCredit Start
	this->fileIO->getAccountList()->at(currentUser).setBalance(newBalance);

	string username = this->fileIO->getAccountList()->at(currentUser).getUsername();
	string type = this->fileIO->getAccountList()->at(currentUser).getType();

	AuxiliaryTransaction add (Entry::addcredit, username, newBalance, type);
	this->transaction->push_back(add);

	return true;
}

bool Transaction::addcredit(string username, double amount) {

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
		// User is not admin
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(user).getBalance() + amount;

	if (newBalance > Account::maxCredit) {
		// Will exceed maximum credit balance
		return false;
	}

	// AddCredit Start
	this->fileIO->getAccountList()->at(user).setBalance(newBalance);

	string type = this->fileIO->getAccountList()->at(user).getType();
	AuxiliaryTransaction add (Entry::addcredit, username, newBalance, type);
	this->transaction->push_back(add);
    return true;
}

bool Transaction::refund(string buyName, string sellName, double amount) {

	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::admin) != 0) {
		// User is not admin
		return false;
	}

	int buyer = this->fileIO->findUser(buyName);
	int seller = this ->fileIO->findUser(sellName);

	if (buyer == -1) {
		// Buyer does not exist
		return false;
	}

	if (seller == -1) {
		// Seller does not exist
		return false;
	}

	string buyerType = this->fileIO->getAccountList()->at(buyer).getType();
	string sellerType = this->fileIO->getAccountList()->at(seller).getType();

	if (buyerType.compare(Account::sell) == 0) {
		// Buyer does not have buy privileges
		return false;
	}

	if (sellerType.compare(Account::buy) == 0) {
		// Seller does not have sell privileges
		return false;
	}

	double newBuyerBalance = this->fileIO->getAccountList()->at(buyer).getBalance() + amount;
	double newSellerBalance = this->fileIO->getAccountList()->at(seller).getBalance() - amount;

	if (newBuyerBalance > Account::maxCredit) {
		// New balance will exceed maximum credit balance
		return false;
	}

	if (newSellerBalance < 0) {
		// Seller does not have enough credit
		return false;
	}

	// Refund Start
	this->fileIO->getAccountList()->at(seller).setBalance(newSellerBalance);
	this->fileIO->getAccountList()->at(buyer).setBalance(newBuyerBalance);

	Refund refund (Entry::refund, buyName, sellName, amount);
    throw "Not yet implemented";
}

bool Transaction::initTransaction() {
    if (!transaction->empty()) {
    	transaction->clear();
    }

    /**
     * TODO Read in user accounts and available tickets. Apply daily
     * transactions to these files
     */

    return true;
}

FileIO* Transaction::getFileIO() {
	return this->fileIO;
}

int Transaction::getCurrentUser() {
	return this->currentUser;
}

bool Transaction::isAdmin() {
	if (this->currentUser == -1) {
		return false;
	}
	if (this->fileIO->getAccountList()->at(currentUser).getType().compare(
			Account::admin) == 0) {
		return true;
	}
	return false;
}

bool Transaction::isLoggedIn() {
	if (this->currentUser == -1) {
		return false;
	}
	return true;
}
