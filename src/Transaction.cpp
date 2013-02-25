#include "../include/Transaction.h"

Transaction::Transaction(string accountPath, string availTicketPath)
: fileIO(new FileIO()), transaction
(new vector<Entry>()) {}

Transaction::~Transaction() {
	delete transaction;
    delete fileIO;
}

bool Transaction::login() {
	//check if transaction list is empty
	if (this->transaction->empty()) {
		//read in uao and ato files

		if (this->fileIO->initialize()) {
			//initialize transaction list
			this->transaction = new vector<Entry>();

			return true;
		}
	}

    return false;
}

bool Transaction::logout() {
	//write to daily transaction file
	if (this->fileIO->writeTransaction(this->transaction)) {
	    // Apparently, committing suicide is legal behaviour
	    //~Transaction();
		delete this;
	}

	return false;
}

bool Transaction::buy(string buyName, string event, int numTickets,
		string sellName) {
	// verify valid input
	// buyer's name, event, and seller's name must exist
		// assume buyer name is correct TODO: implement
	// seller must be selling tickets for event
	// there must be enough tickets available
	// maximum of 4 tickets can be purchased, minimum of 1
	// buyer must have sufficient funds
	// seller's credit must not exceed maximum after transaction
	// buyer must have buy privileges
		// seller can buy back their own tickets
	int buyer = this->fileIO->findUser(buyName);
	if (buyer == -1) {
		return false;
	}

	if ((this->fileIO->getAccountList()->at(buyer).getType()
			.compare(Account::sell) != 0) && ((this->fileIO->getAccountList()
			->at(buyer).getType().compare(Account::admin) != 0 &&
			numTickets <= 4 && numTickets > 0) ||
			this->fileIO->getAccountList()->at(buyer).getType()
			.compare(Account::admin) == 0)) {

		int ticket = this->fileIO->findEvent(event, sellName);

		if (ticket != 0) {
			double cost = this->fileIO->getTicketList()->at(ticket).getCost()
					* numTickets;

			if (this->fileIO->getAccountList()->at(buyer).getBalance()
					>= cost) {
				int seller = this->fileIO->findUser(sellName);

				if (seller == 0) {
					return false;
				}

				if ((this->fileIO->getAccountList()->at(buyer).getBalance()
						+ cost) > Account::maxPrice) {
					return false;
				}

				// buy start
				// remove cost from buyer's account
				// add cost to seller's account
				// remove number of tickets from event
					// delete event if it no longer has tickets
				// write to daily transaction file

				this->fileIO->getAccountList()->at(buyer).setBalance(
						this->fileIO->getAccountList()->at(buyer).getBalance()
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

			}
		}
	}

    return false;
}

bool Transaction::sell(string sellName, string event, double salePrice,
		int availTicket) {
	//sellName and must not be null
		//sell must exist, must have sell privilege,
		//must not have an event with the given event name already listed
	//salePrice cant be greater than 999.99 and greater than 0
	//availTicket must be less than 100 and greater than 0

	int seller = this->fileIO->findUser(sellName);
	//if(this->fileIO->accountList->at(seller).getUsername())
	if (seller == -1) {
		// Seller not found
		return false;
	}

	if (this->fileIO->getAccountList()->at(seller).getType()
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

	this->fileIO->updateAvailTickets();

	EventTransaction sell (Entry::sell, event, sellName, salePrice, availTicket);

	this->transaction->push_back(sell);

	return true;
}

bool Transaction::create(string newUser, string accountType,
		double accountBalance) {
    throw "Not yet implemented";
}

bool Transaction::removeUser(string username) {
    throw "Not yet implemented";
}

bool Transaction::addcredit(string username, double amount) {
    throw "Not yet implemented";
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
