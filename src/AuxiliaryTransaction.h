class AuxiliaryTransaction : Entry {

private:
	string username;
	double credit;
	string type;

public:
	string getUsername();

	void setUsername(string username);

	double getCredit();

	void setCredit(double credit);

	string getType();

	void setType(string type);
};
