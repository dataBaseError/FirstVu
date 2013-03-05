#include "../include/Main.h"
#include "../include/Main.h"

//using Poco::StringTokenizer;

int main(int argc, char** argv) {
    if (argc == 4) {
        Transaction* session = new Transaction(argv[1], argv[2], argv[3]);

        string input, username, type, event, seller;
        double balance, price;
        int ticketNum;
        bool success = false;

        while (getline(cin, input)) {
            //cout << "Enter your command." << endl;
            input = rtrim(input);
            if (!session->isLoggedIn()) {
                if (input.compare("login") == 0) {
                    // Log in stuff.
                    cout << "enter username" << endl;
                    getline(cin, input);

                    if (!validUsername(input)) {
                        cout << "error: invalid username" << endl;
                    }
                    else {
                        if (session->login(input)) {
                            cout << "login successful" << endl;
                        }
                    }
                }
                else if (input.compare("quit") == 0) {
                    session->quit();
                    break;
                }
                else if (input.compare("logout") == 0
                        || input.compare("buy") == 0
                        || input.compare("create") == 0
                        || input.compare("sell") == 0
                        || input.compare("refund") == 0
                        || input.compare("addcredit") == 0
                        || input.compare("delete") == 0) {
                    cout << "error: no users logged in" << endl;
                }
                else {
                    cout << "error: invalid command" << endl;
                }
            }
            else {
                if (input.compare("login") == 0) {
                    cout << "error: user is already logged in" << endl;
                }
                else if (input.compare("logout") == 0) {
                    session->logout();
                    cout << "logout successful" << endl;
                }
                else if (input.compare("create") == 0) {
                    cout << "enter username to create" << endl;
                    getline(cin, username);

                    if (!validUsername(username)) {
                        cout << "error: invalid username" << endl;
                    }
                    else {
                        cout << "enter account type" << endl;
                        getline(cin, type);

                        if (!validAccountType(type)) {
                            cout << "error: invalid account type" << endl;
                        }
                        else {
                            cout << "enter user account balance" << endl;
                            //getline(cin, balance);
                            cin >> balance;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (!fail) {
                                if (!validBalance(balance)) {
                                    cout << "error: amount added cannot be greater than $1000.00" << endl;
                                }
                                else {
                                    if (session->create(username, type, balance)) {
                                        cout << "create successful" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (input.compare("delete") == 0) {
                    if (session->isAdmin()) {
                        cout << "enter username" << endl;
                        getline(cin, username);

                        if (!validUsername(username)) {
                            cout << "error: invalid username" << endl;
                        }
                        else {
                            if (session->removeUser(username)) {
                                cout << "delete successful" << endl;
                            }
                        }
                    }
                    else if (input.compare("addcredit") == 0) {
                        if (session->isAdmin()) {
                            cout << "enter username" << endl;
                            getline(cin, username);

                            if (!validUsername(username)) {
                                cout << "error: invalid username" << endl;
                            }
                            // else?
                        }

                        if (session->getFileIO()->findUser(username) != -1) {
                            cout << "enter credit amount" << endl;
                            //getline(cin, balance);
                            cin >> balance;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (fail) {
                                cout << "error: invalid credit amount" << endl;
                            }
                            else {
                                success = false;

                                if (!validBalance(balance)) {
                                    cout << "error: amound added cannot be greater than $1000.00" << endl;
                                }
                                else {
                                    if (!session->isAdmin()) {
                                        success = session->addcredit(balance);
                                    }
                                    else {
                                        success = session->addcredit(username, balance);
                                    }

                                    if (success) {
                                        //cout << "new balance: $" << session->getFileIO()->getAccountList()->at(session->getCurrentUser()).getBalance() << endl;
                                        cout << "credit added" << endl;
                                    }
                                }
                            }
                        }
                        else {
                            cout << "error: username does not exist" << endl;
                        }
                    }
                    else if (input.compare("sell") == 0) {
                        cout << "enter event title" << endl;
                        getline(cin, event);

                        if (!validEventName(event)) {
                            cout << "error: invalid event name" << endl;
                        }
                        else {
                            cout << "enter sale price" << endl;
                            //getline(cin, price);
                            cin >> price;

                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (!fail) {
                                if (!validPrice(price)) {
                                    cout << "error: invalid event price" << endl;
                                }
                                else {
                                    cout << "enter number of tickets" << endl;
                                    //getline(cin, ticketNum);
                                    cin >> ticketNum;
                                    fail = cin.fail();

                                    // Skip to next line
                                    getline(cin, dummy);

                                    if (!fail) {
                                        if (session->sell(event, price, ticketNum)) {
                                            cout << "tickets added" << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if (input.compare("buy") == 0) {
                        cout << "enter event title" << endl;
                        getline(cin, event);

                        if (!validEventName(event)) {
                            cout << "error: invalid event name" << endl;
                        }
                        else {
                            cout << "enter number of tickets" << endl;
                            //getline(cin, ticketNum);

                            cin >> ticketNum;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (fail || ticketNum <= 0) {
                                cout << "error: invalid ticket number" << endl;
                            } else {
                                cout << "enter username of seller" << endl;
                                getline(cin, seller);

                                if (!validUsername(seller)) {
                                    cout << "error: invalid seller name" << endl;
                                }
                                else {
                                    if (session->buy(event, ticketNum, seller)) {
                                        cout << "purchase successful" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else if (input.compare("refund") == 0) {
                        cout << "enter buyer's username" << endl;
                        getline(cin, username);

                        if (!validUsername(username)) {
                            cout << "error: invalid username" << endl;
                        }
                        else {
                            cout << "enter seller's username" << endl;
                            getline(cin, seller);

                            if (!validUsername(username)) {
                                cout << "error: invalid username" << endl;
                            }
                            else {
                                cout << "enter amount to transfer" << endl;
                                //getline(cin, balance);
                                cin >> balance;

                                if (!validBalance(balance)) {
                                    cout << "error: invalid transfer amount" << endl;
                                }
                                else {
                                    if (session->refund(username, seller, balance)) {
                                        cout << "refund successful" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        cout << "error: invalid command" << endl;
                    }
                }

                //cout << endl;
            }
        }

        //cout << endl;

        return 0;
    }
}
