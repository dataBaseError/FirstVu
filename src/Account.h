#include <string>

using namespace std;

class Account {

private:
    string username;
    string type;
    double balance;

public:
    const string admin = "AA";
    const string sell  = "SS";
    const string buy   = "BS";
    const string full  = "FS";
    const double maxPrice = 999999.99;

    string getType();

    void setType(string type);

    double getBalance();

    void setBalance(double balance);

    string getUsername();

    void setUsername(string username);
};
