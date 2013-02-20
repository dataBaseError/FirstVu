#include "FileIO.h"

bool FileIO::initialize() {
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

Account FileIO::findUser(string username) {
    throw "Not yet implemented";
}

Ticket FileIO::findEvent(string event, string sellName) {
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
