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
            // TODO Trim right side of the input
            if (!session->isLoggedIn()) {
                if (input.compare("login") == 0) {
                    // Log in stuff.
                    cout << "enter username" << endl;
                    getline(cin, input);

                    if (session->login(input)) {
                        cout << "login successful" << endl;
                    }
                }
                else if (input.compare("quit") == 0) {
                	session->quit();
                    break;
                }
                else {
                    cout << "error: invalid command" << endl;
                }
            }
            else {
                if (input.compare("logout") == 0) {
                    session->logout();
                    cout << "logout successful" << endl;
                }
                else if (input.compare("create") == 0) {
                    cout << "enter username to create" << endl;
                    getline(cin, username);

                    // TODO: Catch create1 testcase
                    // username must be maximum 15 characters

                    cout << "enter account type" << endl;
                    getline(cin, type);

                    cout << "enter user account balance" << endl;
                    //getline(cin, balance);
                    cin >> balance;

                    if (session->create(username, type, balance)) {
                        cout << "create successful" << endl;
                    }
                }
                else if (input.compare("delete") == 0) {
                    cout << "enter username" << endl;
                    getline(cin, username);

                    if (session->removeUser(username)) {
                        cout << "delete successful" << endl;
                    }
                }
                else if (input.compare("addcredit") == 0) {
                    if (session->isAdmin()) {
                        cout << "enter username" << endl;
                        getline(cin, username);
                    }

                    cout << "enter credit amount" << endl;
                    //getline(cin, balance);
                    cin >> balance;

                    success = false;

                    success = validBalance(balance);

                    if (session->isAdmin()) {
                        success = session->addcredit(balance);
                    }
                    else {
                        success = session->addcredit(username, balance);
                    }

                    if (success) {
                        cout << "credit added" << endl;
                    }
                }
                else if (input.compare("sell") == 0) {
                    cout << "enter event title" << endl;
                    getline(cin, event);

                    cout << "enter sale price" << endl;
                    //getline(cin, price);
                    cin >> price;

                    cout << "enter number of tickets" << endl;
                    //getline(cin, ticketNum);
                    cin >> ticketNum;

                    if (session->sell(event, price, ticketNum)) {
                        cout << "tickets added" << endl;
                    }
                }
                else if (input.compare("buy") == 0) {
                    cout << "enter event title" << endl;
                    getline(cin, event);

                    cout << "enter number of tickets" << endl;
                    //getline(cin, ticketNum);
                    cin >> ticketNum;

                    // Skip to next line
                    while (cin.get() != '\n');

                    cout << "enter username of seller" << endl;
                    getline(cin, seller);

                    if (session->buy(event, ticketNum, seller)) {
                        cout << "purchase successful" << endl;
                    }
                }
                else if (input.compare("refund") == 0) {
                    cout << "enter buyer's username" << endl;
                    getline(cin, username);

                    cout << "enter seller's username" << endl;
                    getline(cin, seller);

                    cout << "enter amount to transfer" << endl;
                    //getline(cin, balance);
                    cin >> balance;

                    if (session->refund(username, seller, balance)) {
                        cout << "refund successful" << endl;
                    }
                }
                else {
                    cout << "error: invalid command" << endl;
                }
            }
            //cout << endl;
        }
    }

    cout << endl;

    return 0;
}
