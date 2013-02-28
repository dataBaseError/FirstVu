#include "../include/Main.h"

using Poco::StringTokenizer;
int main (int argc, char** argv) {

    //Transaction* session = new Transaction("", "");
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
