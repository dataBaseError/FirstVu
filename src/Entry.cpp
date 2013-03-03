#include "../include/Entry.h"

const int Entry::LOGOUT    = 0;
const int Entry::CREATE    = 1;
const int Entry::DEL       = 2;
const int Entry::SELL      = 3;
const int Entry::BUY       = 4;
const int Entry::REFUND    = 5;
const int Entry::ADDCREDIT = 6;

// TODO make this better needs to be 00 followed by 29 spaces.
const string EMPTY_ENTRY = "00                             ";

Entry::Entry(int transactionType) {
	this->transactionType = transactionType;
}

Entry::~Entry() {
	// Don't need, 'int' is a primitive type
    // delete &transactionType;
}

int Entry::getTransactionType() {
	return this->transactionType;
}
void Entry::setTransactionType(int transactionType) {
	this->transactionType = transactionType;
}

string Entry::getDTFLine() {
    return "";
}
