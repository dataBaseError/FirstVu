class eventTransactions : Entry {

private:
	string eventName;
	string sellName;
	double price;
	int numTickets;

public:
	string getSellName();

	void setSellName(string sellName);

	string getEventName();

	void setEventName(string eventName);

	double getPrice();

	void setPrice(double price);

	int getNumTickets();

	void setNumTickets(int numTickets);
};
