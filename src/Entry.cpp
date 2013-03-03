#include "../include/Entry.h"

const int Entry::logout    = 0;
const int Entry::create    = 1;
const int Entry::del       = 2;
const int Entry::sell      = 3;
const int Entry::buy       = 4;
const int Entry::refund    = 5;
const int Entry::addcredit = 6;

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
