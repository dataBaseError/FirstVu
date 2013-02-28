#include "../include/FileIO.h"

<<<<<<< HEAD

FileIO::FileIO(string ticketFile, string userFile){
	accountList = new vector<Account>();
	ticketList = new vector<Ticket>();
	this->ticketFile = ticketFile;
	this->userFile = userFile;

=======
FileIO::FileIO() {
	this->accountList = new vector<Account>();
	this->ticketList = new vector<Ticket>();
>>>>>>> de1584c25cbeea1e9c500cf7336a45271a4fb587
}

FileIO::~FileIO() {
	delete accountList;
	delete ticketList;
}


bool FileIO::initialize() {
	//Read in lists
	//Poco::FileInputStream *stream1 = new Poco::FileInputStream(ticketFile);
	//string file = "../tests/login/login.inp";
	Poco::FileInputStream* stream1 = new Poco::FileInputStream("../tests/login/login.inp");


	Poco::FileInputStream *stream2 = new Poco::FileInputStream(userFile);
	while(!stream1->eof()){
		string test;
		//*stream1 >> test;
		getline(*stream1,test);
		cout << test;
	}

	while(!stream2->eof()){
	//	string test;
	//	*stream2 >> test;
	}
    //throw "Not yet implemented";
	delete stream1;
	delete stream2;
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
