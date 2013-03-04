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
    //TODO REMOVE
    //vector<Entry>* entries = this->readDailyTransaction();
    //Read in lists
    //throw "Not yet implemented";
    //this
    return updateAccountList() && updateTicketList();
}

vector<Entry>* FileIO::readDailyTransaction() {
    /**
     * Read in the daily transaction file
     *
     * This will be implemented to allow for the program to be shut off and then
     * re-initialized. Currently not implemented for the prototype.
     */
    throw "Not yet implemented";
}

/**
 * This will read in the user accounts from memory and update it based on the
 * daily transaction file
 */
bool FileIO::updateAccountList() {
    //TODO REMOVE
    //vector<Entry>* entries = this->readDailyTransaction();

    //for (vector<Entry>::iterator iterator = entries->begin(); iterator != entries->end(); iterator++) {
    //    iterator->
    //}

    ifstream uao;
    uao.open(this->uao);

    if (uao.is_open()) {
        while (!uao.eof()) {
            string line;

            getline(uao, line);
            vector<string> lineV = split(line, '\n');

            for (vector<string>::size_type i = 0; i < lineV.size(); i++) {
                vector<string> accountV = split(lineV.at(i), ' ');

                if (accountV[0] != "END") {
                    string username = accountV[0];
                    string type = accountV[1];

                    stringstream ss(stringstream::in | stringstream::out);
                    ss << accountV[2];

                    double balance;
                    ss >> balance;

                    Account* account = new Account(username, type, balance);
                    this->accountList->push_back(*account);
                    delete account;
                }
            }
        }

        uao.close();
        return true;
    }
    else {
        return false;
    }
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

            getline(ato, line);
            vector<string> lineV = split(line, '\n');

            for (vector<string>::size_type i = 0; i < lineV.size(); i++) {
                vector<string> ticketV = split(lineV.at(i), ' ');

                if (ticketV[0] != "END") {
                    string event = ticketV[0];
                    string username = ticketV[1];

                    stringstream ss(stringstream::in | stringstream::out);
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
        ato.close();

        // Return true if successful read
        return true;
    }

    // File could not be opened return false
    return false;
}

bool FileIO::writeTransaction(vector<Entry>* newList) {

    ofstream dtf(this->dtf, ios::app);

    if (dtf.is_open()) {
        for (vector<Entry>::size_type i = 0; i < newList->size(); i++) {
            // Write to file given path
            dtf << newList->at(i).getDTFLine();
        }

        dtf << Entry::EMPTY_ENTRY;
        dtf.close();
        return true;
    }
    return false;
}

int FileIO::findUser(string username) {
    for (vector<Account>::size_type i = 0; i < this->accountList->size(); i++) {
        if (this->accountList->at(i).getUsername() == username) {
            return i;
        }
    }

    return -1;
}

int FileIO::findEvent(string event, string sellName) {
    for (vector<Ticket>::size_type i = 0; i < this->ticketList->size(); i++) {
        if (this->ticketList->at(i).getEvent() == event && this->ticketList->at(i).getUsername() == sellName) {
            return i;
        }
    }

    return -1;
}

bool FileIO::isUserUnique(string username) {
    bool found = false;

    for (vector<Account>::size_type i = 0; i < this->accountList->size(); i++) {
        if (this->accountList->at(i).getUsername() == username) {
            if (found) {
                return false;
            }
            else {
                found = true;
            }
        }
    }

    return found;
}

bool FileIO::isEventUnique(string event, string sellName) {
    bool found = false;

    for (vector<Ticket>::size_type i = 0; i < this->ticketList->size(); i++) {
        Ticket item = this->ticketList->at(i);

        if (item.getEvent() == event && item.getUsername() == sellName) {
            if (found) {
                return false;
            }
            else {
                found = true;
            }
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
