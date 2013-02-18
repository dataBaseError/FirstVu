#include "EntryList.h"

Vector<Entry> EntryList::getDailyTransactions() {
	return this->dailyTransactions;
}

void EntryList::setDailyTransactions(Vector<Entry> dailyTransactions) {
	this->dailyTransactions = dailyTransactions;
}
