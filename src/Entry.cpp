#include "Entry.h"

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
