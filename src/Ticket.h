#include <string>

using namespace std;

class Ticket {

private:
    string event;
    string userName;
    int ticketNumber;
    double cost;

public:
    string getEvent();

    void setEvent(string event);

    string getUserName();

    void setUserName(string userName);

    int getTicketNumber();

    void setTicketNumber(int ticketNumber);

    double getCost();

    void setCost(double cost);
};
