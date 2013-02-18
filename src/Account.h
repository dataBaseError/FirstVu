class Account {

private:
	string username;
	string type;
	double balance;

public:
	string getType();

	void setType(string type);

	double getBalance();

	void setBalance(double balance);

	string getUsername();

	void setUsername(string username);
};
