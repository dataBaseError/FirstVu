#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <cstdio>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

/**
 * Class that allows for entries to the daily transaction file.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class Entry {

private:
	int transactionType;

public:

	static const int LOGOUT;
	static const int CREATE;
	static const int DEL;
	static const int SELL;
	static const int BUY;
	static const int REFUND;
	static const int ADDCREDIT;

	static const string EMPTY_ENTRY;

	/**
	 * Constructor for creating an entry.
	 *
	 * @param transactionType the type of transaction.
	 */
	explicit Entry(int transactionType);

	/**
	 * De-constructor for delete an entry.
	 */
	virtual ~Entry();

	/**
	 * Accessor method for getting the type of transaction.
	 *
	 * @return the type of transaction.
	 */
	int getTransactionType();

	/**
	 * Mutator method for setting the transaction type.
	 *
	 * @param transactionType the type of transaction
	 */
	void setTransactionType(int transactionType);

	/**
	 * Returns a line which will be used to write to the
	 * daily transaction file
	 *
	 * @return the entry as it would show up in the daily transaction file
	 */
	virtual string getDTFLine() = 0;
};

#endif // _ENTRY_H_