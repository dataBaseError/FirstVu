#include "../include/FileIO.h"

FileIO::FileIO() {
	//Initialize the lists
}

FileIO::~FileIO() {
	delete &accountList;
	delete &ticketList;
}


bool FileIO::initialize() {
	//Read in lists
    //throw "Not yet implemented";
	return false;
}

bool FileIO::updateUserAccounts(vector<Account> newList) {
    throw "Not yet implemented";
}

bool FileIO::updateAvailTickets(vector<Ticket> newList) {
    throw "Not yet implemented";
}

bool FileIO::writeTransaction(vector<Entry> newList) {
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

vector<Account> FileIO::getAccountList(){
	return this->accountList;
}

vector<Ticket> FileIO::getTicketList(){
	return this->ticketList;
}
