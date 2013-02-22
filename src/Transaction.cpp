#include "Transaction.h"

Transaction::Transaction() : fileIO(*new FileIO()){}

Transaction::~Transaction() {
	delete &transaction;
    delete &fileIO;
}

bool Transaction::login() {
	//check if transaction list is empty
	if (this->transaction.empty()) {
		//read in uao and ato files

		if (this->fileIO.initialize()) {
			//initialize transaction list
			this->transaction = *new vector<Entry>();
		}
	}

    return false;
}

bool Transaction::logout() {
	//write to daily transaction file
	if (this->fileIO.writeTransaction(this->transaction)) {
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
	// maximum of 4 tickets can be purchased
	// buyer must have sufficient funds
	// seller's credit must not exceed maximum after transaction
	// buyer must have buy privileges
		// seller can buy back their own tickets
	int buyer = this->fileIO.findUser(buyName);
	if (buyer == NULL) {
		return false;
	}

	if (this->fileIO.getAccountList(). != buyer.sell) {
		if ((buyer.getType() != buyer.admin && numTickets <= 4) ||
				buyer.getType() == buyer.admin) {
			int ticket = this->fileIO.findEvent(event, sellName);

			if (ticket != NULL) {
				double cost = ticket.getCost() * numTickets;

				if (buyer.getBalance() >= cost) {
					int seller = this->fileIO.findUser(sellName);

					if (seller == NULL) {
						return false;
					}

					if ((seller.getBalance() + cost) > seller.maxPrice) {
						return false;
					}

					// buy start
					// remove cost from buyer's account
					// add cost to seller's account
					// remove number of tickets from event
						// delete event if it no longer has tickets
					// write to daily transaction file

					buyer.setBalance(buyer.getBalance() - cost);
					seller.setBalance(seller.getBalance() + cost);
					ticket.decreaseTicketNumber(numTickets);
					if (ticket.getTicketNumber() == 0) {
						//ticket.
					}
				}

			}
		}
	}

    return false;
}

bool Transaction::sell(string sellName, string event, double salePrice,
		int availTicket) {
    throw "Not yet implemented";
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

FileIO Transaction::getFileIO() {
	return this->fileIO;
}
