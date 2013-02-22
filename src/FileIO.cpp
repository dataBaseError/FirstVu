#include "FileIO.h"

FileIO::FileIO(){
	//Initialize the lists
}

bool FileIO::initialize() {
	//Read in lists
    throw "Not yet implemented";
}

bool FileIO::updateUserAccounts(AccountList newList) {
    throw "Not yet implemented";
}

bool FileIO::updateAvailTickets(TicketList newList) {
    throw "Not yet implemented";
}

bool FileIO::writeTransaction(EntryList newList) {
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

AccountList FileIO::getAccountList(){
	return this->accountList;
}

TicketList FileIO::getTicketList(){
	return this->ticketList;
}
