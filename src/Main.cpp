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
                    cout << ENTER_USERNAME << endl;
                    getline(cin, input);

                    if (!validUsername(input)) {
                        cout << INVALID_USERNAME << endl;
                    }
                    else {
                        if (session->login(input)) {
                            cout << LOGIN_SUCCESS << endl;
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
                    cout << USER_NOT_LOGGED_IN << endl;
                }
                else {
                    cout << INVALID_COMMAND << endl;
                }
            }
            else {
                if (input.compare("login") == 0) {
                    cout << USER_ALREADY_LOGGED << endl;
                }
                else if (input.compare("logout") == 0) {
                    session->logout();
                    cout << LOGIN_SUCCESS << endl;
                }
                else if (input.compare("create") == 0) {
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
                            //getline(cin, balance);
                            cin >> balance;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (!fail) {
                                if (!validBalance(balance)) {
                                    cout << INVALID_ACCOUNT_BALANCE << endl;
                                }
                                else {
                                    if (session->create(username, type, balance)) {
                                        cout << CREATE_SUCCESS << endl;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (input.compare("delete") == 0) {
                    if (session->isAdmin()) {
                        cout << ENTER_USERNAME << endl;
                        getline(cin, username);

                        if (!validUsername(username)) {
                            cout << INVALID_USERNAME << endl;
                        }
                        else {
                            if (session->removeUser(username)) {
                                cout << DELETE_SUCCESS << endl;
                            }
                        }
                    }
                }
                else if (input.compare("addcredit") == 0) {
                    if (session->isAdmin()) {
                        cout << ENTER_USERNAME << endl;
                        getline(cin, username);

                        if (!validUsername(username)) {
                            cout << INVALID_USERNAME << endl;
                        }
                        // else?

                        if (session->getFileIO()->findUser(username) != -1) {
                            cout << ENTER_CREDIT_AMOUNT << endl;
                            //getline(cin, balance);
                            cin >> balance;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (fail) {
                                cout << INVALID_CREDIT_AMOUNT << endl;
                            }
                            else {
                                if (!validBalance(balance)) {
                                    cout << INVALID_CREDIT_AMOUNT << endl;
                                }
                                else if (session->addcredit(username, balance)) {
                                    //cout << "new balance: $" << session->getFileIO()->getAccountList()->at(session->getCurrentUser()).getBalance() << endl;
                                    cout << ADDCREDIT_SUCCESS << endl;
                                }
                            }
                        }
                    }
                    else {
                        cout << ENTER_CREDIT_AMOUNT << endl;
                        //getline(cin, balance);
                        cin >> balance;
                        bool fail = cin.fail();

                        // Skip to next line
                        string dummy;
                        getline(cin, dummy);

                        if (fail) {
                        	cout << INVALID_CREDIT_AMOUNT << endl;
                        }
                        else {
                            success = false;

                            if (!validBalance(balance)) {
                                cout << INVALID_CREDIT_AMOUNT << endl;
                            }
                            else if (session->addcredit(balance)) {
                                //cout << "new balance: $" << session->getFileIO()->getAccountList()->at(session->getCurrentUser()).getBalance() << endl;
                                cout << ADDCREDIT_SUCCESS << endl;
                            }
                        }
                    }
                }
                else if (input.compare("sell") == 0) {
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

                        // Skip to next line
                        string dummy;
                        getline(cin, dummy);

                        if (fail) {
                        	cout << INVALID_EVENT_PRICE << endl;
                        }
                        else {
                        	if (!validPrice(price)) {
								cout << INVALID_EVENT_PRICE << endl;
							}
                        	else {
                                cout << ENTER_TICKET_NUMBER << endl;
                                //getline(cin, ticketNum);
                                cin >> ticketNum;
                                fail = cin.fail();

                                // Skip to next line
                                getline(cin, dummy);

                                if (fail) {
                                	cout << INVALID_TICKET_NUMBER << endl;
                                }
                                else {
                                	if (!validTicketNumber(ticketNum)) {
                                		cout << INVALID_TICKET_NUMBER << endl;
                                	}
                                	else if (session->sell(event, price, ticketNum)) {
										cout << SELL_SUCCESS << endl;
									}

                                }
                            }
                        }
                    }
                }
                else if (input.compare("buy") == 0) {
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

                        // Skip to next line
                        string dummy;
                        getline(cin, dummy);

                        if (fail) {
                            cout << INVALID_TICKET_NUMBER << endl;
                        } else {

                        	if(!validTicketNumber(ticketNum)) {
                        		cout << INVALID_TICKET_NUMBER << endl;
                        	}

                            cout << ENTER_SELLER << endl;
                            getline(cin, seller);

                            if (!validUsername(seller)) {
                                cout << INVALID_SELLER << endl;
                            }
                            else {
                                if (session->buy(event, ticketNum, seller)) {
                                    cout << BUY_SUCCESS << endl;
                                }
                            }
                        }
                    }
                }
                else if (input.compare("refund") == 0) {
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
                            //getline(cin, balance);
                            cin >> balance;
                            bool fail = cin.fail();

                            // Skip to next line
                            string dummy;
                            getline(cin, dummy);

                            if (fail) {
                            	cout << INVALID_TRANSFER_AMOUNT << endl;
                            }
                            else {
                                if (!validBalance(balance)) {
                                    cout << INVALID_TRANSFER_AMOUNT << endl;
                                }
                                else {
                                    if (session->refund(username, seller, balance)) {
                                        cout << REFUND_SUCCESS << endl;
                                    }
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
    }

    return 0;
}
