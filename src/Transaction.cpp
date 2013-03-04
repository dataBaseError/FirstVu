#include "../include/Transaction.h"

const double Transaction::maxAddCredit = 1000.00;

Transaction::Transaction(char* accountPath, char* availTicketPath,
		char* dailyTransactionPath) {
	this->currentUser = -1;
	this->transaction = new vector<Entry*>();

	this->fileIO = new FileIO(accountPath, availTicketPath, dailyTransactionPath);
}

Transaction::~Transaction() {
	delete transaction;
    delete fileIO;
}

// TODO add error messages.
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

			return true;
		}
	}

    return false;
}

bool Transaction::logout() {
	if(currentUser == -1) {
		// No user logged in
		return false;
	}

	Account currentUser = this->fileIO->getAccountList()->at(this->currentUser);

	AuxiliaryTransaction* exitUser = new AuxiliaryTransaction (Entry::LOGOUT, currentUser.getUsername(),
			currentUser.getBalance(),
			currentUser.getType());
	this->transaction->push_back(exitUser);
	this->currentUser = -1;

	return true;
}

bool Transaction::buy(string event, int numTickets, string sellName) {
	if (currentUser == -1) {
		// No user logged in
		return false;
	}


	if(this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::SELL) == 0) {
		// User does not have buy privileges
		return false;
	}

	if (numTickets <= 0) {
		// Not enough tickets purchased
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0 && numTickets > 4) {
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
			+ cost) > Account::MAX_CREDIT) {
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
	EventTransaction* buy = new EventTransaction(Entry::BUY, event, sellName, ticketCost, numTickets);

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
			.compare(Account::BUY) == 0){
		// Invalid privileges
		return false;
	}
	if (availTicket <= 0 || availTicket > Ticket::MAX_TICKET) {
		// Invalid number of Tickets
		return false;
	}

	if (salePrice < 0 || salePrice > Ticket::MAX_PRICE) {
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

	EventTransaction* sell = new EventTransaction(Entry::SELL, event, sellName, salePrice, availTicket);
	this->transaction->push_back(sell);

	return true;
}

bool Transaction::create(string newUser, string accountType,
		double accountBalance) {

	if (currentUser == -1) {
		// No user logged in
		return false;
	}

	if (accountType.compare(Account::BUY) != 0 &&
			accountType.compare(Account::SELL) != 0 &&
			accountType.compare(Account::FULL) != 0 &&
			accountType.compare(Account::ADMIN) != 0) {
		// Invalid account type
		return false;
	}

	if (accountBalance < 0 || accountBalance > Account::MAX_CREDIT) {
		// Invalid credit
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
		// Invalid user privileges
		return false;
	}

	// Create Start
	Account newAccount(newUser, accountType, accountBalance);
	this->fileIO->getAccountList()->push_back(newAccount);

	AuxiliaryTransaction* createUser = new AuxiliaryTransaction(Entry::CREATE, newUser, accountBalance,
			accountType);
	this->transaction->push_back(createUser);

	return true;
}

bool Transaction::removeUser(string username) {
	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
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

	AuxiliaryTransaction* removeUser = new AuxiliaryTransaction(Entry::DEL, username, balance, type);
	this->transaction->push_back(removeUser);

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

	if (newBalance > Account::MAX_CREDIT) {
		// Will exceed maximum credit balance
		return false;
	}

	// AddCredit Start
	this->fileIO->getAccountList()->at(currentUser).setBalance(newBalance);

	string username = this->fileIO->getAccountList()->at(currentUser).getUsername();
	string type = this->fileIO->getAccountList()->at(currentUser).getType();

	AuxiliaryTransaction* add = new AuxiliaryTransaction(Entry::ADDCREDIT, username, newBalance, type);
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
			.compare(Account::ADMIN) != 0) {
		// User is not admin
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(user).getBalance() + amount;

	if (newBalance > Account::MAX_CREDIT) {
		// Will exceed maximum credit balance
		return false;
	}

	// AddCredit Start
	this->fileIO->getAccountList()->at(user).setBalance(newBalance);
	string type = this->fileIO->getAccountList()->at(user).getType();

	AuxiliaryTransaction* add = new AuxiliaryTransaction(Entry::ADDCREDIT, username, newBalance, type);
	this->transaction->push_back(add);
    return true;
}

bool Transaction::refund(string buyName, string sellName, double amount) {
	if (currentUser == -1) {
		// No user is logged in
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
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

	if (buyerType.compare(Account::SELL) == 0) {
		// Buyer does not have buy privileges
		return false;
	}

	if (sellerType.compare(Account::BUY) == 0) {
		// Seller does not have sell privileges
		return false;
	}

	double newBuyerBalance = this->fileIO->getAccountList()->at(buyer)
			.getBalance() + amount;
	double newSellerBalance = this->fileIO->getAccountList()->at(seller)
			.getBalance() - amount;

	if (newBuyerBalance > Account::MAX_CREDIT) {
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

	Refund refund (Entry::REFUND, buyName, sellName, amount);

	return true;
}

bool Transaction::quit() {
	if (this->fileIO->writeTransaction(this->transaction)) {
		this->transaction->clear();
		return true;
	}

	// Error writing dtf.
	return false;
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
			Account::ADMIN) == 0) {
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
