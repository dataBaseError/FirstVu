#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "Account.h"
#include "Entry.h"
#include "Ticket.h"
#include "utility.h"

using namespace std;

/**
 * A class for reading in all of the different input files and outputting to all
 * of the appropriate output files.
 *
 * @author Ryan Crawford
 * @author Khalil Fazal
 * @author Joseph Heron
 * @author Carly Marshall
 */
class FileIO {

private:
    char* uao;
    char* ato;
    char* dtf;
	vector<Account>* accountList;
	vector<Ticket>* ticketList;

	/**
	 * Read in the current daily transaction file.
	 *
	 * @return The list of transactions previously recored in the daily
	 * transactions file.
	 */
	vector<Entry>* readDailyTransaction();

	 /**
	 * Reads in the User Account File and stores it in the AccountList vector.
	 *
	 * @return Whether the user accounts list update was successful.
	 */
	bool updateAccountList();

	 /**
	 * Reads in the Ticket List file and stores it in the TicketList.
	 *
	 * @return Whether the event ticket list update was successful.
	 */
	 bool updateTicketList();


public:

	/**
	 * Constructor for creating a new FileIO object, initializes two vectors on
	 * the creation of the object.
	 *
	 * @param uao The path of the user accounts file.
	 * @param ato The path of the available tickets file.
	 * @param dtf The path of the daily transactions file.
	 */
	FileIO(char* uao, char* ato, char* dtf);

	~FileIO();

	/**
	 * Method for reading in initial input files (available tickets and user
	 * account files) and creating a new list for the daily transaction file.
	 *
	 * @return Whether the initialization was successful.
	 */
    bool initialize();

	/**
	 * Writes all of the transactions to the end of the daily.
	 *
	 * @param newList The list of daily transactions to be added to the daily
	 * transaction file.
	 * @return Whether the write to the daily transaction file was successful.
	 */
    bool writeTransaction(vector<Entry*> newList);

    /**
     * Checks if the given string matches any username in the current user
     * accounts file.
     *
     * @param username The username to find in the user accounts list.
     * @return The index of the user in the user accounts list, if the user is
     * not found it will be -1.
     */
    int findUser(string username);

    /**
     * Checks if there is an event with the given name registered to the given
     * seller.
     *
     * @param event The name of the event to look for in the event ticket list.
     * @param sellName The name of the user who is selling tickets for the event
     * being looked for in the event ticket list.
     * @return The index of the event in the event ticket list, if the event is
     * not found the index will be -1;
     */
    int findEvent(string event, string sellName);

    /**
     * Checks to see if the given username is valid and unique.
     *
     * @param username The username to check.
     * @return Whether the username is valid and unique.
     */
    bool isUserUnique(string username);

    /**
     * Checks to see if the given event is valid and unique.
     *
     * @param event The name of the event.
     * @param sellName The seller's username.
     * @return Whether the event is valid and unique for that user.
     */
    bool isEventUnique(string event, string sellName);

    /**
     * Accessor method for getting the list of accounts.
     *
     * @return The list of accounts.
     */
    vector<Account>* getAccountList();

    /**
     * Accessor method for getting the list of ticket.
     *
     * @return The list of tickets.
     */
    vector<Ticket>* getTicketList();
};

#endif // _FILEIO_H_
