#include "Entry.h";

Entry::Entry(int transactionType) {
	this->transactionType = transactionType;
}

Entry::~Entry() {
	delete transactionType;
}

int Entry::getTransactionType() {
	return this->transactionType;
}
void Entry::setTransactionType(int transactionType) {
	this->transactionType = transactionType;
}
