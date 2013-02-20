#include <vector>

using namespace std;

/**
 * A data structure of event transactions.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class EntryList {

private:
    vector<Entry> dailyTransactions;

public:

    /**
     * Constructor for creating the list of daily transactions.
     *
     * @param dailyTransactions the list of daily transactions
     */
    EntryList(vector<Entry> dailyTransations);


    /**
     * Constructor for creating a new daily transaction list.
     */
    EntryList();

    ~EntryList();

    /**
     * Accessor method for getting the daily transactions.
     *
     * @return The list of daily transactions
     */
    vector<Entry> getDailyTransactions();

    /**
     * Mutator method for setting the list of daily transactions.
     *
     * @param
     */
    void setDailyTransactions(vector<Entry> dailyTransactions);
};
