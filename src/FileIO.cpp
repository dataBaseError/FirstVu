#include "../include/FileIO.h"

//TODO add daily transaction file path as argument.
FileIO::FileIO(char* uao, char* ato, char* dtf) {
    this->uao = uao;
    this->ato = ato;
    this->dtf = dtf;

	this->accountList = new vector<Account>();
	this->ticketList = new vector<Ticket>();
}

FileIO::~FileIO() {
	delete accountList;
	delete ticketList;
}


bool FileIO::initialize() {
    //vector<Entry>* entries = this->readDailyTransaction();
	//Read in lists
    //throw "Not yet implemented";
    //this
	return updateAccountList() && updateTicketList();
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
    //vector<Entry>* entries = this->readDailyTransaction();

    //for (vector<Entry>::iterator iterator = entries->begin(); iterator != entries->end(); iterator++) {
    //    iterator->
    //}

    ifstream uao;
    uao.open(this->uao);

    if (uao.is_open()) {
        while (!uao.eof()) {
            string line;

            uao >> line;
            vector<string> lineV = split(line, '\n');

            for (vector<string>::iterator iterator = lineV.begin(); iterator != lineV.end(); iterator++) {
                vector<string> accountV = split(*iterator, ' ');

                if (accountV[0] != "END") {
                    string username = accountV[0];
                    string type = accountV[1];

                    stringstream ss (stringstream::in | stringstream::out);
                    ss << accountV[2];

                    double balance;
                    ss >> balance;

                    Account* account = new Account(username, type, balance);
                    this->accountList->push_back(*account);
                    delete account;
                }
            }
        }
    }

    return true;
}

/**
 * This will read in the user accounts from memory and update it based on the
 * daily transaction file
 */
bool FileIO::updateTicketList() {
    ifstream ato;
    ato.open(this->ato);

    if (ato.is_open()) {
        while (!ato.eof()) {
            string line;

            ato >> line;
            vector<string> lineV = split(line, '\n');

            for (vector<string>::iterator iterator = lineV.begin(); iterator != lineV.end(); iterator++) {
                vector<string> ticketV = split(*iterator, ' ');

                if (ticketV[0] != "END") {
                    string event = ticketV[0];
                    string username = ticketV[1];

                    stringstream ss (stringstream::in | stringstream::out);
                    ss << ticketV[2];

                    int num;
                    ss >> num;

                    ss << ticketV[3];

                    double price;
                    ss >> price;

                    Ticket* ticket = new Ticket(event, username, num, price);
                    this->ticketList->push_back(*ticket);
                    delete ticket;
                }
            }
        }
    }

    return true;
}

bool FileIO::writeTransaction(vector<Entry>* newList) {
    throw "Not yet implemented";
}

int FileIO::findUser(string username) {
    for (vector<Account>::size_type i = 0; i != this->accountList->size(); i++) {
        if (this->accountList->at(i).getUsername() == username) {
            return i;
        }
    }

    return -1;
}

int FileIO::findEvent(string event, string sellName) {
    for (vector<Ticket>::size_type i = 0; i != this->ticketList->size(); i++) {
        if (this->ticketList->at(i).getEvent() == event && this->ticketList->at(i).getUsername() == sellName) {
            return i;
        }
    }

    return -1;
}

bool FileIO::isUserUnique(string username) {
    bool found = false;

    for (vector<Account>::size_type i = 0; i != this->accountList->size(); i++) {
        if (found) {
            return false;
        } else {
            found = true;
        }
    }

    return found;
}

bool FileIO::isEventUnique(string event, string sellName) {
    bool found = false;

    for (vector<Ticket>::size_type i = 0; i != this->ticketList->size(); i++) {
        if (found) {
            return false;
        } else {
            found = true;
        }
    }

    return found;
}

vector<Account>* FileIO::getAccountList() {
	return this->accountList;
}

vector<Ticket>* FileIO::getTicketList() {
	return this->ticketList;
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}
