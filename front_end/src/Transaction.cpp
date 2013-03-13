#include <Transaction.h>

const double Transaction::maxAddCredit = 1000.00;

Transaction::Transaction(char* accountPath, char* availTicketPath,
        char* dailyTransactionPath) {
    this->currentUser = -1;
    this->transaction = new vector<Entry*>();

    this->fileIO = new FileIO(accountPath, availTicketPath, dailyTransactionPath);

    this->fileIO->initialize();
}

Transaction::~Transaction() {
    delete transaction;
    delete fileIO;
}

bool Transaction::login(string username) {
    currentUser = this->fileIO->findUser(username);
    if (currentUser == -1) {
        cout << INVALID_USERNAME_EXIST << endl;
        return false;
    }

    return true;
}

bool Transaction::logout() {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    Account currentUser = this->fileIO->getAccountList()->at(this->currentUser);

    AuxiliaryTransaction* exitUser = new AuxiliaryTransaction(Entry::LOGOUT, currentUser.getUsername(),
            currentUser.getBalance(),
            currentUser.getType());

    this->transaction->push_back(exitUser);
    this->currentUser = -1;

    return true;
}

bool Transaction::buy(string event, int numTickets, string sellName) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    vector<Account>* accountList = this->fileIO->getAccountList();
    Account buyer = accountList->at(currentUser);

    if (buyer.getType().compare(Account::SELL) == 0) {
        cout << INVALID_ACCOUNT_BUY << endl;
        return false;
    }

    if (numTickets <= 0) {
        cout << INVALID_TICKET_REMAINING << endl;
        return false;
    }

    if (accountList->at(currentUser).getType().compare(Account::ADMIN) != 0 && numTickets > 4) {
        cout << INVALID_TICKET_MAX << endl;
        return false;
    }

    int seller = this->fileIO->findUser(sellName);

    if (seller == -1) {
        cout << INVALID_SELLER << endl;
        return false;
    }

    int ticket = this->fileIO->findEvent(event, sellName);

    if (ticket == -1) {
        cout << INVALID_EVENT_TITLE << endl;
        return false;
    }

    vector<Ticket>* ticketList = this->fileIO->getTicketList();
    Ticket eventTickets = ticketList->at(ticket);

    double cost = eventTickets.getCost() * numTickets;

    if (buyer.getBalance() < cost) {
        cout << INVALID_FUNDS << endl;
        return false;
    }

    if ((accountList->at(seller).getBalance() + cost) > Account::MAX_CREDIT) {
        cout << INVALID_SELLER_BALANCE << endl;
        return false;
    }

    string answer;

    // Buy Start
    cout << TICKET_COST << setiosflags(ios::fixed) << setprecision(2) << eventTickets.getCost() << endl;
    cout << TOTAL_COST << setiosflags(ios::fixed) << setprecision(2) << cost << endl;
    cout << CURRENT_BALANCE << setiosflags(ios::fixed) << setprecision(2) << buyer.getBalance() << endl;
    cout << CONFIRM_PURCHASE << endl;
    getline(cin, answer);

    if (answer.compare("yes") == 0) {
        buyer.setBalance(buyer.getBalance() - cost);

        cout << NEW_BALANCE << buyer.getBalance() << endl;

        accountList->at(seller).setBalance(accountList->at(seller).getBalance() + cost);

        eventTickets.decreaseTicketNumber(numTickets);

        if (eventTickets.getTicketNumber() == 0) {
            // Delete ticket
            ticketList->erase(ticketList->begin() + ticket);
        }

        double ticketCost = eventTickets.getCost();

        // Add transaction to transaction list
        EventTransaction* buy = new EventTransaction(Entry::BUY, event, sellName, ticketCost, numTickets);

        this->transaction->push_back(buy);

        return true;
    }

    return false;
}

bool Transaction::sell(string event, double salePrice, int availTicket) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    string sellName = this->fileIO->getAccountList()->at(currentUser).getUsername();

    if (this->fileIO->getAccountList()->at(currentUser).getType()
            .compare(Account::BUY) == 0) {
        cout << INVALID_ACCOUNT_SELL << endl;
        return false;
    }
    if (availTicket < 1 || availTicket > Ticket::MAX_TICKET) {
        cout << INVALID_TICKET_NUMBER << endl;
        return false;
    }

    if (salePrice < 0 || salePrice > Ticket::MAX_PRICE) {
        cout << INVALID_EVENT_PRICE << endl;
        return false;
    }

    if (this->fileIO->findEvent(event, sellName) > -1) {
        cout << INVALID_EVENT_EXIST << endl;
        return false;
    }

    // Sell start
    Ticket newEvent(event, sellName, availTicket, salePrice);

    this->fileIO->getTicketList()->push_back(newEvent);

    EventTransaction* sell = new EventTransaction(Entry::SELL, event, sellName, salePrice, availTicket);
    this->transaction->push_back(sell);

    return true;
}

bool Transaction::create(string newUser, string accountType,
        double accountBalance) {

    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    if (accountType.compare(Account::BUY) != 0 &&
            accountType.compare(Account::SELL) != 0 &&
            accountType.compare(Account::FULL) != 0 &&
            accountType.compare(Account::ADMIN) != 0) {
        cout << INVALID_ACCOUNT_TYPE << endl;
        return false;
    }

    if (accountBalance < 0 || accountBalance > Account::MAX_CREDIT) {
        cout << INVALID_CREDIT_AMOUNT << endl;
        return false;
    }

    if (this->fileIO->getAccountList()->at(currentUser).getType()
            .compare(Account::ADMIN) != 0) {
        cout << INVALID_ADMIN_CREATE << endl;
        return false;
    }

    // Create Start
    Account newAccount(newUser, accountType, accountBalance);
    this->fileIO->getAccountList()->push_back(newAccount);

    AuxiliaryTransaction* createUser = new AuxiliaryTransaction(Entry::CREATE, newUser, accountBalance,
            accountType);
    this->transaction->push_back(createUser);

    return true;
}

bool Transaction::removeUser(string username) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    if (this->fileIO->getAccountList()->at(currentUser).getType()
            .compare(Account::ADMIN) != 0) {
        cout << INVALID_ADMIN_DELETE << endl;
        return false;
    }

    int user = this->fileIO->findUser(username);

    if (user == -1) {
        cout << INVALID_USERNAME_EXIST << endl;
        return false;
    }

    if (currentUser == user) {
        cout << INVALID_DELETE << endl;
        return false;
    }

    // Delete Start
    string type = this->fileIO->getAccountList()->at(user).getType();
    double balance = this->fileIO->getAccountList()->at(user).getBalance();

    this->fileIO->getAccountList()->erase(this->fileIO
            ->getAccountList()->begin() + (user),
            this->fileIO->getAccountList()->begin() + user + 1);

    AuxiliaryTransaction* removeUser = new AuxiliaryTransaction(Entry::DEL, username, balance, type);
    this->transaction->push_back(removeUser);

    return true;
}

bool Transaction::addcredit(double amount) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    if (amount > Transaction::maxAddCredit) {
        cout << INVALID_CREDIT_AMOUNT << endl;
        return false;
    }

    double newBalance = this->fileIO->getAccountList()->at(currentUser)
            .getBalance() + amount;

    if (newBalance > Account::MAX_CREDIT) {
        cout << INVALID_ADD_BALANCE << endl;
        return false;
    }

    // AddCredit Start
    this->fileIO->getAccountList()->at(currentUser).setBalance(newBalance);

    string username = this->fileIO->getAccountList()->at(currentUser).getUsername();
    string type = this->fileIO->getAccountList()->at(currentUser).getType();

    AuxiliaryTransaction* add = new AuxiliaryTransaction(Entry::ADDCREDIT, username, amount, type);
    this->transaction->push_back(add);

    cout << NEW_BALANCE << newBalance << endl;

    return true;
}

bool Transaction::addcredit(string username, double amount) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    int user = this->fileIO->findUser(username);
    if (user == -1) {
        cout << INVALID_USERNAME_EXIST << endl;
        return false;
    }

    if (amount > Transaction::maxAddCredit) {
        cout << INVALID_CREDIT_AMOUNT << endl;
        return false;
    }

    if (this->fileIO->getAccountList()->at(currentUser).getType()
            .compare(Account::ADMIN) != 0) {
        cout << INVALID_ADMIN_ADD << endl;
        return false;
    }

    double newBalance = this->fileIO->getAccountList()->at(user).getBalance() + amount;

    if (newBalance > Account::MAX_CREDIT) {
        cout << INVALID_ADD_BALANCE << endl;
        return false;
    }

    // AddCredit Start
    this->fileIO->getAccountList()->at(user).setBalance(newBalance);
    string type = this->fileIO->getAccountList()->at(user).getType();

    AuxiliaryTransaction* add = new AuxiliaryTransaction(Entry::ADDCREDIT, username, amount, type);
    this->transaction->push_back(add);

    cout << NEW_BALANCE << newBalance << endl;
    return true;
}

bool Transaction::refund(string buyName, string sellName, double amount) {
    if (currentUser == -1) {
        cout << USER_NOT_LOGGED_IN << endl;
        return false;
    }

    if (this->fileIO->getAccountList()->at(currentUser).getType()
            .compare(Account::ADMIN) != 0) {
        cout << INVALID_ADMIN_REFUND << endl;
        return false;
    }

    int buyer = this->fileIO->findUser(buyName);
    int seller = this->fileIO->findUser(sellName);

    if (buyer == -1) {
        cout << INVALID_USERNAME_EXIST << endl;
        return false;
    }

    if (seller == -1) {
        cout << INVALID_USERNAME_EXIST << endl;
        return false;
    }

    string buyerType = this->fileIO->getAccountList()->at(buyer).getType();
    string sellerType = this->fileIO->getAccountList()->at(seller).getType();

    if (buyerType.compare(Account::SELL) == 0
            || sellerType.compare(Account::BUY) == 0) {
        cout << INVALID_ADMIN_ADD << endl;
        return false;
    }

    double newBuyerBalance = this->fileIO->getAccountList()->at(buyer)
            .getBalance() + amount;
    double newSellerBalance = this->fileIO->getAccountList()->at(seller)
            .getBalance() - amount;

    if (newBuyerBalance > Account::MAX_CREDIT) {
        cout << INVALID_ADD_BALANCE << endl;
        return false;
    }

    if (newSellerBalance < 0) {
        cout << INVALID_FUNDS << endl;
        return false;
    }

    // Refund Start
    this->fileIO->getAccountList()->at(seller).setBalance(newSellerBalance);
    this->fileIO->getAccountList()->at(buyer).setBalance(newBuyerBalance);

    Refund refund(Entry::REFUND, buyName, sellName, amount);

    return true;
}

bool Transaction::quit() {
    if (this->fileIO->writeTransaction(*this->transaction)) {
        this->transaction->clear();
        return true;
    }

    //cout << "Error writing dtf.";
    return false;
}

FileIO* Transaction::getFileIO() {
    return this->fileIO;
}

int Transaction::getCurrentUser() {
    return this->currentUser;
}

bool Transaction::isAdmin() {
    if (this->currentUser == -1) {
        return false;
    }

    if (this->fileIO->getAccountList()->at(currentUser).getType().compare(
            Account::ADMIN) == 0) {
        return true;
    }
    return false;
}

bool Transaction::isLoggedIn() {
    if (this->currentUser == -1) {
        return false;
    }
    return true;
}
