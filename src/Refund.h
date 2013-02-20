class refund : Entry {

private:
	string buyName;
	string sellName;
	double credit;

public:
	string getBuyName();

	void setBuyName(string buyName);

	string getSellName();

	void setSellName(string sellName);

	double getCredit();

	void setCredit(double credit);
};
