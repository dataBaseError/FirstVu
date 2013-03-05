#include "../include/FileIO.h"

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
    return updateAccountList() && updateTicketList();
}

/**
 * This will read in the user accounts from memory and update it based on the
 * daily transaction file
 */
bool FileIO::updateAccountList() {
    ifstream uao;
    uao.open(this->uao);

    if (uao.is_open()) {
        while (!uao.eof()) {
            string line;

            getline(uao, line);
            vector<string> lineV = split(line, ' ');

            if (lineV[0] != "END") {
                string username = lineV[0];
                string type = lineV[1];

                stringstream ss(stringstream::in | stringstream::out);
                ss << lineV[2];

                double balance;
                ss >> balance;

                Account* account = new Account(username, type, balance);
                this->accountList->push_back(*account);
                delete account;
            } else {
                break;
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
            vector<string> lineV = split(line, ' ');

            if (lineV[0] != "END") {
                string event = lineV[0];
                string username = lineV[1];

                stringstream ss(stringstream::in | stringstream::out);
                ss << lineV[2];

                int num;
                ss >> num;

                ss.clear();
                ss << lineV[3];

                double price;
                ss >> price;

                Ticket* ticket = new Ticket(event, username, num, price);
                this->ticketList->push_back(*ticket);
                delete ticket;
            } else {
                break;
            }
        }
        ato.close();

        // Return true if successful read
        return true;
    }

    // File could not be opened return false
    return false;
}

bool FileIO::writeTransaction(vector<Entry*> newList) {
    ofstream dtf(this->dtf, ios::app);

    if (dtf.is_open()) {
        for (vector<Entry*>::size_type i = 0; i < newList.size(); i++) {
            // Write to file given path
            string entry = newList[i]->getDTFLine();
            dtf << entry;
        }

        dtf << Entry::EMPTY_ENTRY << endl;
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
	//cout << ticketList->size() << endl;
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
