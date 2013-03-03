#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <fstream>
#include <string>

#include "Account.h"
#include "Entry.h"
#include "Ticket.h"
#include "utility.h"

using namespace std;

class FileIO {

private:
    char* uao;
    char* ato;
    char* dtf;
	vector<Account>* accountList;
	vector<Ticket>* ticketList;

	vector<Entry>* readDailyTransaction();

    bool updateAccounts();

	bool updateTickets();

public:

	FileIO(char* uao, char* ato,char* dtf);

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
