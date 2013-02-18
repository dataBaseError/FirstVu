#include <vector>

using namespace std;

class EntryList {

private:
    vector<Entry> dailyTransactions;

public:
    vector<Entry> getDailyTransactions();

    void setDailyTransactions(vector<Entry> dailyTransactions);
};
