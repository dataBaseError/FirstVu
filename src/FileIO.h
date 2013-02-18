#include <string>

using namespace std;

class FileIO {

public:
    bool initialize();

    bool updateUserAccounts(AccountList newList);

    bool updateAvailTickets(TicketList newList);

    bool writeTransaction(EntryList newList);

    Account findUser(string username);

    Ticket findEvent(string event, string sellName);

    bool isUserUnique(string username);

    bool isEventUnique(string event, string sellName);
};
