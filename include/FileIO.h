#include <string>
#include <vector>
#include <istream>
#include <iostream>

#include "Account.h"
#include "Entry.h"
#include "Ticket.h"

//#include "../lib/include/Poco/File.h"
#include "../lib/include/Poco/FileStream.h"

using namespace std;

class FileIO {

private:
	vector<Account>* accountList;
	vector<Ticket>* ticketList;
	string ticketFile;
	string userFile;

	vector<Entry>* readDailyTransaction();

    bool updateAccounts();

	bool updateTickets();

public:

	FileIO(string userFile, string ticketFile);

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
