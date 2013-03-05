#include "../include/Transaction.h"

const double Transaction::maxAddCredit = 1000.00;

Transaction::Transaction(char* accountPath, char* availTicketPath,
		char* dailyTransactionPath) {
	this->currentUser = -1;
	this->transaction = new vector<Entry*>();

	this->fileIO = new FileIO(accountPath, availTicketPath, dailyTransactionPath);

	this->fileIO->initialize();
}

Transaction::~Transaction() {
	delete transaction;
    delete fileIO;
}

// TODO add error messages.
bool Transaction::login(string username) {
	// Check if transaction list is empty
	//if (currentUser == -1) {

		// Read in uao and ato files
		//if () {

			currentUser = this->fileIO->findUser(username);
			if (currentUser == -1) {
				cout << "error: username does not exist" << endl;
				return false;
			}

			return true;
		//}
	//}

	//cout << "error: user is already logged in";
    //return false;
}

bool Transaction::logout() {
	if(currentUser == -1) {
		// No user logged in
		cout << "No user logged in" << endl;
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
		cout << "No user logged in" << endl;
		return false;
	}

	vector<Account>* accountList = this->fileIO->getAccountList();
	Account buyer = accountList->at(currentUser);


	if(buyer.getType().compare(Account::SELL) == 0) {
		cout << "User does not have buy privileges" << endl;
		return false;
	}

	if (numTickets <= 0) {
		cout << "Not enough tickets purchased" << endl;
		return false;
	}

	if (accountList->at(currentUser).getType().compare(Account::ADMIN) != 0 && numTickets > 4) {
		cout << "User cannot buy more than 4 tickets" << endl;
		return false;
	}

	int seller = this->fileIO->findUser(sellName);

	if (seller == -1) {
		cout << "Seller does not exist" << endl;
		return false;
	}

	int ticket = this->fileIO->findEvent(event, sellName);

	if (ticket == -1) {
		cout << "Event does not exist" << endl;
		return false;
	}

	vector<Ticket>* ticketList = this->fileIO->getTicketList();
	Ticket eventTickets = ticketList->at(ticket);

	double cost = eventTickets.getCost() * numTickets;

	if (buyer.getBalance() < cost) {
		cout << "User has insufficient funds" << endl;
		return false;
	}

	if ((buyer.getBalance()	+ cost) > Account::MAX_CREDIT) {
		cout << "Seller's funds will exceed max price" << endl;
		return false;
	}

	// TODO: Add confirmation of purchase

	// Buy Start
	buyer.setBalance(buyer.getBalance()	- cost);

	accountList->at(seller).setBalance(accountList->at(seller).getBalance()	+ cost);

	eventTickets.decreaseTicketNumber(numTickets);

	if (eventTickets.getTicketNumber() == 0) {
		// Delete ticket
	    ticketList->erase(ticketList->begin() + (ticket - 1), ticketList->begin() + ticket);
	}

	double ticketCost = eventTickets.getCost();

	// Add transaction to transaction list
	EventTransaction* buy = new EventTransaction(Entry::BUY, event, sellName, ticketCost, numTickets);

	this->transaction->push_back(buy);

    return true;
}

bool Transaction::sell(string event, double salePrice, int availTicket) {
	if (currentUser == -1) {
		cout << "No user is logged in" << endl;
		return false;
	}

	string sellName = this->fileIO->getAccountList()->at(currentUser).getUsername();

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::BUY) == 0){
		cout << "Invalid privileges" << endl;
		return false;
	}
	if (availTicket <= 0 || availTicket > Ticket::MAX_TICKET) {
		cout << "Invalid number of Tickets" << endl;
		return false;
	}

	if (salePrice < 0 || salePrice > Ticket::MAX_PRICE) {
		cout << "Invalid Ticket Price" << endl;
		return false;
	}

	if (this->fileIO->findEvent(event, sellName) >= 0) {
		cout << "Event already exists" << endl;
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
		cout << "No user logged in" << endl;
		return false;
	}

	if (accountType.compare(Account::BUY) != 0 &&
			accountType.compare(Account::SELL) != 0 &&
			accountType.compare(Account::FULL) != 0 &&
			accountType.compare(Account::ADMIN) != 0) {
		cout << "Invalid account type" << endl;
		return false;
	}

	if (accountBalance < 0 || accountBalance > Account::MAX_CREDIT) {
		cout << "Invalid credit" << endl;
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
		cout << "Invalid user privileges" << endl;
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
		cout << "No user is logged in" << endl;
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
		 cout << "Invalid user privileges" << endl;
		return false;
	}

	int user = this->fileIO->findUser(username);

	if (user == -1) {
		cout << "User does not exist" << endl;
		return false;
	}

	if (currentUser == user) {
		cout << "Cannot delete self" << endl;
		return false;
	}

	// Delete Start
	string type = this->fileIO->getAccountList()->at(user).getType();
	double balance = this->fileIO->getAccountList()->at(user).getBalance();

	this->fileIO->getAccountList()->erase(this->fileIO
					->getAccountList()->begin() + (user),
					this->fileIO->getAccountList()->begin() + user+1);
	//TODO REMOVE
	/*for (int i = 0; i < fileIO->getAccountList()->size(); i++) {
		cout << fileIO->getAccountList()->at(i).getUsername() << endl;
	}*/

	AuxiliaryTransaction* removeUser = new AuxiliaryTransaction(Entry::DEL, username, balance, type);
	this->transaction->push_back(removeUser);

	return true;
}

bool Transaction::addcredit(double amount) {
	if (currentUser == -1) {
		cout << "No user is logged in" << endl;
		return false;
	}

	if (amount > Transaction::maxAddCredit) {
		cout << "Invalid credit amount" << endl;
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(currentUser)
			.getBalance() + amount;

	if (newBalance > Account::MAX_CREDIT) {
		cout << "Will exceed maximum credit balance" << endl;
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
		cout << "No user is logged in" << endl;
		return false;
	}

	int user = this->fileIO->findUser(username);
	if (user == -1) {
		cout << "User does not exist" << endl;
		return false;
	}

	if (amount > Transaction::maxAddCredit) {
		cout << "Invalid credit amount" << endl;
		return false;
	}


	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
		cout << "User is not admin" << endl;
		return false;
	}

	double newBalance = this->fileIO->getAccountList()->at(user).getBalance() + amount;

	if (newBalance > Account::MAX_CREDIT) {
		cout << "Will exceed maximum credit balance" << endl;
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
		cout << "No user is logged in" << endl;
		return false;
	}

	if (this->fileIO->getAccountList()->at(currentUser).getType()
			.compare(Account::ADMIN) != 0) {
		cout << "User is not admin" << endl;
		return false;
	}

	int buyer = this->fileIO->findUser(buyName);
	int seller = this ->fileIO->findUser(sellName);

	if (buyer == -1) {
		cout << "Buyer does not exist" << endl;
		return false;
	}

	if (seller == -1) {
		cout <<  "Seller does not exist" << endl;
		return false;
	}

	string buyerType = this->fileIO->getAccountList()->at(buyer).getType();
	string sellerType = this->fileIO->getAccountList()->at(seller).getType();

	if (buyerType.compare(Account::SELL) == 0) {
		cout << "Buyer does not have buy privileges" << endl;
		return false;
	}

	if (sellerType.compare(Account::BUY) == 0) {
		cout << "Seller does not have sell privileges" << endl;
		return false;
	}

	double newBuyerBalance = this->fileIO->getAccountList()->at(buyer)
			.getBalance() + amount;
	double newSellerBalance = this->fileIO->getAccountList()->at(seller)
			.getBalance() - amount;

	if (newBuyerBalance > Account::MAX_CREDIT) {
		cout << "New balance will exceed maximum credit balance" << endl;
		return false;
	}

	if (newSellerBalance < 0) {
		cout << "Seller does not have enough credit" << endl;
		return false;
	}

	// Refund Start
	this->fileIO->getAccountList()->at(seller).setBalance(newSellerBalance);
	this->fileIO->getAccountList()->at(buyer).setBalance(newBuyerBalance);

	Refund refund (Entry::REFUND, buyName, sellName, amount);

	return true;
}

bool Transaction::quit() {
	if (this->fileIO->writeTransaction(*this->transaction)) {
		this->transaction->clear();
		return true;
	}

	cout << "Error writing dtf." << endl;
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
