#include "../include/Main.h"

// Stupid VP
// main takes argc and argv
// We have to parse argv to get the file names

int main (int argc, char** argv) {
//int main(string userAccountIn, string availableTicketIn, string dailyTransaction, string userAccountOut, string availableTicketOut) {

    Transaction* session = new Transaction("", "");
	//Transaction session = Transaction();

    string input;
	cout << "Enter your command." << endl;

	getline(cin, input);
	//Trim right side of the input
	if (input.compare("login") == 0) {
		// Log in stuff.
		cout << "Enter username" << endl;
		getline(cin, input);

		session->login(input);
	}

	return 0;
}
