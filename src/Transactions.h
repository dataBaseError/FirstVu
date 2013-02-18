class Transactions {

private:
	Vector<Entry> transactions;

public:
	boolean login();

	boolean logout();

	boolean buy(String buyName, String event, int numTickets, String sellName);

	boolean sell(Sting sellName, String event, double salePrice, int availTicket);

	boolean create(String newUser, String accountType, double accountBalance);

	boolean removeUser(String username);

	boolean addcredit(int username_String, double amount);

	boolean refund(String buyName, String sellName, double amount);

private:
	boolean initTransactions();

	boolean addTransaction(Entry entry);

	boolean writeTransactions();
};
