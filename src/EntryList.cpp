#include <vector>

#include "EntryList.h"

using namespace std;

vector<Entry> EntryList::getDailyTransactions() {
    return this->dailyTransactions;
}

void EntryList::setDailyTransactions(vector<Entry> dailyTransactions) {
    this->dailyTransactions = dailyTransactions;
}
