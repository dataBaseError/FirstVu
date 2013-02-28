#include "../include/Main.h"

// Stupid VP
// main takes argc and argv
// We have to parse argv to get the file names

int main (int argc, char** argv) {
//int main(string userAccountIn, string availableTicketIn, string dailyTransaction, string userAccountOut, string availableTicketOut) {

    Transaction* session = new Transaction("", "");
	//Transaction session = Transaction();

    string input;
    string username;
    string type;
    string event;
    string seller;
    double balance;
    double price;
    int ticketNum;
    bool success = false;

	cout << "Enter your command." << endl;

	getline(cin, input);
	//Trim right side of the input
	if (input.compare("login") == 0) {
		// Log in stuff.
		cout << "Enter username" << endl;
		getline(cin, input);

		if (session->login(input)) {
			cout << "Login successful." << endl;
		}
	}
	else if (input.compare("logout") == 0) {
		session->logout();
	}
	else if (input.compare("create") == 0) {
		cout << "Enter username to create." << endl;
		getline(cin, username);

		cout << "Enter account type." << endl;
		getline(cin, type);

		cout << "Enter user account balance." << endl;
		//getline(cin, balance);
		cin >> balance;

		if (session->create(username, type, balance)) {
			cout << "Create successful." << endl;
		}
	}
	else if (input.compare("delete") == 0) {
		cout << "Enter username." << endl;
		getline(cin, username);

		if (session->removeUser(username)) {
			cout << "Delete successful." << endl;
		}
	}
	else if (input.compare("addcredit") == 0) {
		if (session->isAdmin()) {
			cout << "Enter username." << endl;
			getline(cin, username);
		}

		cout << "Enter credit amount." << endl;
		//getline(cin, balance);
		cin >> balance;

		success = false;
		if (session->isAdmin()) {
			success = session->addcredit(balance);
		}
		else {
			success = session->addcredit(username, balance);
		}

		if (success) {
			cout << "Credit added." << endl;
		}
	}
	else if (input.compare("sell") == 0) {
		cout << "Enter event title." << endl;
		getline(cin, event);

		cout << "Enter sale price." << endl;
		//getline(cin, price);
		cin >> price;

		cout << "Enter number of tickets." << endl;
		//getline(cin, ticketNum);
		cin >> ticketNum;

		if (session->sell(event, price, ticketNum)) {
			cout << "Tickets added." << endl;
		}
	}
	else if (input.compare("buy") == 0) {
		cout << "Enter event title." << endl;
		getline(cin, event);

		cout << "Enter number of tickets." << endl;
		//getline(cin, ticketNum);
		cin >> ticketNum;

		cout << "Enter username of seller." << endl;
		getline(cin, seller);

		// TODO add confirmation into buy transaction.
		if (session->buy(event, ticketNum, seller)) {
			cout << "Purchase successful." << endl;
		}
	}
	else if (input.compare("refund") == 0) {
		cout << "Enter buyer's username." << endl;
		getline(cin, username);

		cout << "Enter seller's username." << endl;
		getline(cin, seller);

		cout << "Enter amount to transfer." << endl;
		//getline(cin, balance);
		cin >> balance;

		if (session->refund(username, seller, balance)) {
			cout << "Refund successful." << endl;
		}

	}
	else if (input.compare("quit") == 0) {
		if (session->isLoggedIn()) {
			cout << "Error: invalid command" << endl;
		}
		else {
			break;
		}
	}
	else {
		cout << "Error: invalid command" << endl;
	}
	}

	return 0;
}
