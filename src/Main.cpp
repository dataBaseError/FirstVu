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
    double balance;

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

		cout << "Enter user account balance."
		//getline(cin, balance);
		cin >> balance;

		if (session->create(username, type, balance)) {
			cout << "Create successful." << endl;
		}
	}
	else if (input.compare("delete") == 0) {

	}
	else if (input.compare("addcredit") == 0) {
		if (session->isAdmin()) {
			cout << "Enter username." << endl;
			getline(cin, username);
		}

		cout << "Enter credit amount." << endl;
		//getline(cin, balance);
		cin >> balance;
	}
	else if (input.compare("sell") == 0) {

	}
	else if (input.compare("buy") == 0) {

	}
	else if (input.compare("refund") == 0) {

	}
	else if (input.compare("quit") == 0) {

	}
	else {
		cout << "Invalid input" << endl;
	}

	return 0;
}
