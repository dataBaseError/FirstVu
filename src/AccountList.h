#include <vector>

using namespace std;

class AccountList {

private:
    vector<Account> accountList;

public:
    vector<Account> getAccountList();

    void setAccountList(vector<Account> accountList);
};
