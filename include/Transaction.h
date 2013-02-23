#include <string>
#include <vector>

#include "Entry.h"
#include "EventTransaction.h"
#include "FileIO.h"

using namespace std;

class Transaction {

private:
	vector<Entry> transaction;
	FileIO fileIO;

public:
	Transaction();

	~Transaction();

	bool login();

	bool logout();

	bool buy(string buyName, string event, int numTickets, string sellName);

	bool sell(string sellName, string event, double salePrice, int availTicket);

	bool create(string newUser, string accountType, double accountBalance);

	bool removeUser(string username);

	bool addcredit(string username, double amount);

	bool refund(string buyName, string sellName, double amount);

	bool initTransaction();

	FileIO getFileIO();
};
