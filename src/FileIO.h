class FileIO {


public:
	boolean initialize();

	boolean updateUserAccounts(AccountList newList);

	boolean updateAvailTickets(TicketList newList);

	boolean writeTransaction(EntryList newList);

	Account findUser(String username);

	Ticket findEvent(String event, String sellName);

	boolean isUserUnique(String username);

	boolean isEventUnique(String event, String sellName);
};
