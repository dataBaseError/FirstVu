#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Account.h"
#include "Entry.h"
#include "Ticket.h"

using namespace std;

// puts the results in an already constructed vector
vector<string> &split(const string &s, char delim, vector<string> &elems);

//returns a new vector
vector<std::string> split(const std::string &s, char delim);

class FileIO {

private:
    char* uao;
    char* ato;
	vector<Account>* accountList;
	vector<Ticket>* ticketList;

	vector<Entry>* readDailyTransaction();

    bool updateAccounts();

	bool updateTickets();

public:

	FileIO(char* uao, char* ato);

	~FileIO();

    bool initialize();

	bool updateAccountList();

	bool updateTicketList();

    bool writeTransaction(vector<Entry>* newList);

    int findUser(string username);

    int findEvent(string event, string sellName);

    bool isUserUnique(string username);

    bool isEventUnique(string event, string sellName);

    vector<Account>* getAccountList();

    vector<Ticket>* getTicketList();
};

#endif // _FILEIO_H_
