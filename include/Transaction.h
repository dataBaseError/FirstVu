#include <string>
#include <vector>

#include "Entry.h"
#include "EventTransaction.h"
#include "FileIO.h"

using namespace std;

class Transaction {

private:
    FileIO* fileIO;
	vector<Entry>* transaction;
	int currentUser;

public:
	static const double maxAddCredit;

	Transaction(string accountPath, string availTicketPath);

	~Transaction();

	bool login(string username);

	bool logout();

	bool buy(string event, int numTickets, string sellName);

	bool sell(string event, double salePrice, int availTicket);

	bool create(string newUser, string accountType, double accountBalance);

	bool removeUser(string username);

	bool addcredit(double amount);

	bool addcredit(string username, double amount);

	bool refund(string buyName, string sellName, double amount);

	bool initTransaction();

	FileIO* getFileIO();
};
