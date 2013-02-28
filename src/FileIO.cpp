#include "../include/FileIO.h"

FileIO::FileIO() {
	this->accountList = new vector<Account>();
	this->ticketList = new vector<Ticket>();
}

FileIO::~FileIO() {
	delete accountList;
	delete ticketList;
}


bool FileIO::initialize() {
	//Read in lists
    //throw "Not yet implemented";
	return false;
}

vector<Entry>* FileIO::readDailyTransaction() {
	/**
	 * Read in the daily transaction file
	 */
	throw "Not yet implemented";
}

/**
 * This will read in the user accounts from memory and update it based on the
 * daily transaction file
 */
bool FileIO::updateAccountList() {
	throw "Not yet implemented";
}

/**
 * This will read in the user accounts from memory and update it based on the
 * daily transaction file
 */
bool FileIO::updateTicketList() {
	throw "Not yet implemented";
}

bool FileIO::writeTransaction(vector<Entry>* newList) {
    throw "Not yet implemented";
}

int FileIO::findUser(string username) {
    throw "Not yet implemented";
}

int FileIO::findEvent(string event, string sellName) {
    throw "Not yet implemented";
}

bool FileIO::isUserUnique(string username) {
    throw "Not yet implemented";
}

bool FileIO::isEventUnique(string event, string sellName) {
    throw "Not yet implemented";
}

vector<Account>* FileIO::getAccountList() {
	return this->accountList;
}

vector<Ticket>* FileIO::getTicketList() {
	return this->ticketList;
}
