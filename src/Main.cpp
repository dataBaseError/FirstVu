#include "../include/Main.h"

// Stupid VP
// main takes argc and argv
// We have to parse argv to get the file names

int main (int argc, char** argv) {
//int main(string userAccountIn, string availableTicketIn, string dailyTransaction, string userAccountOut, string availableTicketOut) {

    Transaction* session = new Transaction();
	//Transaction session = Transaction();

	cout << session->login() << endl;

	cout << "finish" << endl;

	delete session;

	return 0;
}
