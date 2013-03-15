#include <Main.h>

//using Poco::StringTokenizer;

int main(int argc, char** argv) {
    if (argc == 4) {
        Transaction* session = new Transaction(argv[1], argv[2], argv[3]);

        string input, username, type, event, seller, balance;
        double price;
        int ticketNum;

        while (getline(cin, input)) {
            //cout << "Enter your command." << endl;
            //input = rtrim(input);
            input = Poco::trimRight(input);

            if (!session->isLoggedIn()) {
                if (input.compare(LOGIN) == 0) {
                    // Log in stuff.
                    cout << ENTER_USERNAME << endl;
                    getline(cin, input);

                    if (!validUsername(input)) {
                        cout << INVALID_USERNAME_EXIST << endl;
                    }
                    else if (session->login(input)) {
                        cout << LOGIN_SUCCESS << endl;
                    }
                }
                else if (input.compare(QUIT) == 0) {
                    session->quit();
                    break;
                }
                else if (input.compare(LOGOUT) == 0
                        || input.compare(BUY) == 0
                        || input.compare(CREATE) == 0
                        || input.compare(SELL) == 0
                        || input.compare(REFUND) == 0
                        || input.compare(ADDCREDIT) == 0
                        || input.compare(DELETE) == 0) {
                    cout << USER_NOT_LOGGED_IN << endl;
                }
                else {
                    cout << INVALID_COMMAND << endl;
                }
            }
            else if (input.compare(LOGIN) == 0) {
                cout << USER_ALREADY_LOGGED << endl;
            }
            else if (input.compare(LOGOUT) == 0) {
                session->logout();
                cout << LOGOUT_SUCCESS << endl;
            }
            else if (input.compare(CREATE) == 0) {
                cout << CREATE_ENTER_USERNAME << endl;
                getline(cin, username);

                if (!validUsername(username)) {
                    cout << INVALID_USERNAME << endl;
                }
                else {
                    cout << ENTER_ACCOUNT_TYPE << endl;
                    getline(cin, type);

                    if (!validAccountType(type)) {
                        cout << INVALID_ACCOUNT_TYPE << endl;
                    }
                    else {
                        cout << ENTER_ACCOUT_BALANCE << endl;
                        getline(cin, balance);
                        //cin >> balance;

                        if (!validBalance(balance)) {
                            cout << INVALID_ACCOUNT_BALANCE << endl;
                        }
                        else {
                            double validBalance;
                            Poco::DynamicAny(balance).convert(validBalance);

                            if (session->create(username, type, validBalance)) {
                                cout << CREATE_SUCCESS << endl;
                            }
                        }
                    }
                }
            }
            else if (input.compare(DELETE) == 0) {
                //if (session->isAdmin()) {
                    cout << ENTER_USERNAME << endl;
                    getline(cin, username);

                    if (!validUsername(username)) {
                        cout << INVALID_USERNAME << endl;
                    }
                    else if (session->removeUser(username)) {
                        cout << DELETE_SUCCESS << endl;
                    }
                //}
            }
            else if (input.compare(ADDCREDIT) == 0) {
                if (session->isAdmin()) {
                    cout << ENTER_USERNAME << endl;
                    getline(cin, username);

                    if (!validUsername(username)) {
                        cout << INVALID_USERNAME << endl;
                    }
                    //else if (session->getFileIO()->findUser(username) != -1) {
                    else {
                        cout << ENTER_CREDIT_AMOUNT << endl;
                        getline(cin, balance);
                        //cin >> balance;

                        if (!validBalance(balance)) {
                            cout << INVALID_CREDIT_AMOUNT << endl;
                        }
                        else {
                            double validBalance;
                            Poco::DynamicAny(balance).convert(validBalance);

                            if (session->addcredit(username, validBalance)) {
                                //cout << "new balance: $" << session->getFileIO()->getAccountList()->at(session->getCurrentUser()).getBalance() << endl;
                                cout << ADDCREDIT_SUCCESS << endl;
                            }
                        }
                    }
                }
                else {
                    cout << ENTER_CREDIT_AMOUNT << endl;
                    //getline(cin, balance);
                    //cin >> balance;

                    if (getline(cin, balance) && !validBalance(balance)) {
                        cout << INVALID_CREDIT_AMOUNT << endl;
                    }
                    else {
                        double validBalance;
                        Poco::DynamicAny(balance).convert(validBalance);

                        if (session->addcredit(validBalance)) {
                            //cout << "new balance: $" << session->getFileIO()->getAccountList()->at(session->getCurrentUser()).getBalance() << endl;
                            cout << ADDCREDIT_SUCCESS << endl;
                        }
                    }
                }
            }
            else if (input.compare(SELL) == 0) {
                cout << ENTER_EVENT << endl;
                getline(cin, event);

                if (!validEventName(event)) {
                    cout << INVALID_EVENT_TITLE << endl;
                }
                else {
                    cout << ENTER_PRICE << endl;
                    //getline(cin, price);
                    cin >> price;

                    bool fail = cin.fail();
                    cin.clear();

                    // Skip to next line
                    string dummy;
                    getline(cin, dummy);

                    if (fail || !validPrice(price)) {
                        cout << INVALID_EVENT_PRICE << endl;
                    }
                    else {
                        cout << ENTER_TICKET_NUMBER << endl;
                        //getline(cin, ticketNum);
                        cin >> ticketNum;

                        fail = cin.fail();
                        cin.clear();

                        // Skip to next line
                        getline(cin, dummy);

                        if (fail || !validTicketNumber(ticketNum)) {
                            cout << INVALID_TICKET_NUMBER << endl;
                        }
                        else if (session->sell(event, price, ticketNum)) {
                            cout << SELL_SUCCESS << endl;
                        }
                    }
                }
            }
            else if (input.compare(BUY) == 0) {
                cout << ENTER_EVENT << endl;
                getline(cin, event);

                if (!validEventName(event)) {
                    cout << INVALID_EVENT_TITLE << endl;
                }
                else {
                    cout << ENTER_TICKET_NUMBER << endl;
                    //getline(cin, ticketNum);

                    cin >> ticketNum;

                    bool fail = cin.fail();
                    cin.clear();

                    // Skip to next line
                    string dummy;
                    getline(cin, dummy);

                    if (fail || !validTicketNumber(ticketNum)) {
                        cout << INVALID_TICKET_NUMBER << endl;
                    } else {
                        cout << ENTER_SELLER << endl;
                        getline(cin, seller);

                        if (!validUsername(seller)) {
                            cout << INVALID_SELLER << endl;
                        }
                        else if (session->buy(event, ticketNum, seller)) {
                            cout << BUY_SUCCESS << endl;
                        }
                    }
                }
            }
            else if (input.compare(REFUND) == 0) {
                cout << ENTER_BUYER << endl;
                getline(cin, username);

                if (!validUsername(username)) {
                    cout << INVALID_USERNAME << endl;
                }
                else {
                    // todo fix inconsistency
                    cout << ENTER_SELLER << endl;
                    getline(cin, seller);

                    if (!validUsername(username)) {
                        cout << INVALID_USERNAME << endl;
                    }
                    else {
                        cout << ENTER_TRANSFER_AMOUNT << endl;
                        getline(cin, balance);
                        //cin >> balance;

                        if (!validBalance(balance)) {
                            cout << INVALID_TRANSFER_AMOUNT << endl;
                        }
                        else {
                            double validBalance;
                            Poco::DynamicAny(balance).convert(validBalance);

                            if (session->refund(username, seller, validBalance)) {
                                cout << REFUND_SUCCESS << endl;
                            }
                        }
                    }
                }
            }
            else {
                cout << INVALID_COMMAND << endl;
            }
        }
    }

    return 0;
}
