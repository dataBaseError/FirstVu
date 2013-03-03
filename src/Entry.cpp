#include "../include/Entry.h"

const int Entry::LOGOUT    = 0;
const int Entry::CREATE    = 1;
const int Entry::DEL       = 2;
const int Entry::SELL      = 3;
const int Entry::BUY       = 4;
const int Entry::REFUND    = 5;
const int Entry::ADDCREDIT = 6;

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
