#include "AccountList.h"

Vector<Account> AccountList::getAccountList() {
	return this->accountList;
}

void AccountList::setAccountList(Vector<Account> accountList) {
	this->accountList = accountList;
}
