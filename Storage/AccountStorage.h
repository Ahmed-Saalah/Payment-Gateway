#include <iostream> 
#include <vector>
#include "../Models/Account.h"

using namespace std;

class AccountStorage
{
private:
    static vector<Account> Accounts;

public:
    void InsertAccount(const Account &Account)
    {
        Accounts.push_back(Account);
    }

    Account* GetAccountById(int AccountId)
    {
        for(auto &Account : Accounts)
        {
            if(Account.getAccountId() == AccountId)
            {
                return &Account;
            }
        }
        return nullptr;
    }

    bool DeleteAcountId(int AccountId)
    {
        for(auto it = Accounts.begin() ; it != Accounts.end() ; it++ )
        {
            if(it->getAccountId() == AccountId)
            {
                Accounts.erase(it);
                cout<<"Account deleted.\n";
                return true;
            }
        }
        cout << "Account not found.\n";
        return false;
    }

    void DisplayAllAccounts() const
    {
        if (Accounts.empty())
        {
            cout << "No Accounts stored.\n";
            return;
        }

        for (auto Account : Accounts)
        {
            Account.printAccount();
        }
    }

};

vector<Account> AccountStorage::Accounts;