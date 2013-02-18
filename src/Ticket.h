class Ticket {

private:
	String event;
	String userName;
	int ticketNumber;
	double cost;

public:
	String getEvent();

	void setEvent(String event);

	String getUserName();

	void setUserName(String userName);

	int getTicketNumber();

	void setTicketNumber(int ticketNumber);

	double getCost();

	void setCost(double cost);
};
