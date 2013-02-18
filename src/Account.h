class Account {

private:
	String username;
	String type;
	double balance;

public:
	String getType();

	void setType(String type);

	double getBalance();

	void setBalance(double balance);

	String getUsername();

	void setUsername(String username);
};
