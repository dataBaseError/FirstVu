#include <string>
#include <vector>

using namespace std;

class Transactions {

private:
	vector<Entry> transactions;

public:
	bool login();

	bool logout();

	bool buy(string buyName, string event, int numTickets, string sellName);

	bool sell(string sellName, string event, double salePrice, int availTicket);

	bool create(string newUser, string accountType, double accountBalance);

	bool removeUser(string username);

	bool addcredit(int username_string, double amount);

	bool refund(string buyName, string sellName, double amount);

private:
	bool initTransactions();

	bool addTransaction(Entry entry);

	bool writeTransactions();
};
