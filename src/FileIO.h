#include <string>

using namespace std;

class FileIO {

private:
	vector<Account> accountList;
	vector<Ticket> ticketList;

public:

	FileIO();

    bool initialize();

    bool updateUserAccounts(vector<Account> newList);

    bool updateAvailTickets(vector<Ticket> newList);

    bool writeTransaction(vector<Entry> newList);

    int findUser(string username);

    int findEvent(string event, string sellName);

    bool isUserUnique(string username);

    bool isEventUnique(string event, string sellName);

    vector<Account> getAccountList();

    vector<Ticket> getTicketList();
};
