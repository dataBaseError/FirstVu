#include "../include/Entry.h"

const int Entry::logout;
const int Entry::create;
const int Entry::del;
const int Entry::sell;
const int Entry::buy;
const int Entry::refund;
const int Entry::addcredit;

// The 'explicit' keyword is only used in header files
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
