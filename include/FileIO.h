#include <string>
#include <vector>

#include "Account.h"
#include "Entry.h"
#include "Ticket.h"

using namespace std;

class FileIO {

private:
	vector<Account>* accountList;
	vector<Ticket>* ticketList;

	vector<Entry>* readDailyTransaction();

    bool updateAccounts();

	bool updateTickets();

public:

	FileIO();

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
