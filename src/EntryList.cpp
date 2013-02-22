#include <vector>

#include "EntryList.h"

using namespace std;

EntryList::EntryList() {
	this->dailyTransactions = new vector<Entry>;
}

EntryList::EntryList(vector<Entry> dailyTransactions) {
	this->dailyTransactions = dailyTransactions;
}

EntryList::~EntryList() {
	delete dailyTransactions;
}

vector<Entry> EntryList::getDailyTransactions() {
    return this->dailyTransactions;
}

void EntryList::setDailyTransactions(vector<Entry> dailyTransactions) {
    this->dailyTransactions = dailyTransactions;
}
