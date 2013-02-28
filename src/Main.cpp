#include "../include/Main.h"

using Poco::StringTokenizer;
int main (int argc, char** argv) {

<<<<<<< HEAD
	// argv[1]: Ticket File
	// argv[2]: User File
    Transaction* session = new Transaction(argv[1],argv[2]);
=======
    //Transaction* session = new Transaction("", "");
>>>>>>> de1584c25cbeea1e9c500cf7336a45271a4fb587
	//Transaction session = Transaction();

    // Accept user input
    // Tokenize the input
    // Return error for invalid tokens
    // Call appropriate method

    string input;

    cout << "Enter your command" << endl;
    cin >> input;

    StringTokenizer inputTokenizer (",ab,cd,", ",");

	return 0;
}
