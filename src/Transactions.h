class Transactions {


public:
	boolean login();

	boolean logout();

	boolean buy(int String_buyName, int String_event, int int_numTickets, int String_sellName);

	boolean sell(int Sting_sellName, int String_event, int double_salePrice, int int_availTicket);

	boolean create(int String_newUser, int String_accountType, int double_accountBalance);

	boolean removeUser(int String_username);

	boolean addcredit(int String_username, int double_amount);

	boolean refund(int String_buyName, int String_sellName, int double_amount);
};
