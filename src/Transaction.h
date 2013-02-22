#include <string>
#include <vector>

using namespace std;

class Transaction {

private:
	EntryList transaction;

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
};
