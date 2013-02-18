#include <vector>

#include "AccountList.h"

using namespace std;

vector<Account> AccountList::getAccountList() {
    return this->accountList;
}

void AccountList::setAccountList(vector<Account> accountList) {
    this->accountList = accountList;
}
