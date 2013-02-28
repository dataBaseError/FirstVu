#include "../include/Main.h"

//using Poco::StringTokenizer;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

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

    //StringTokenizer inputTokenizer (",ab,cd,", ",");
    vector<string> x = split(",ab,cd,", ',');

	return 0;
}
