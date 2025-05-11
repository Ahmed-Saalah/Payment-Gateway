#pragma once
#include <vector>
#include <iostream>
#include "../Models/Account.h"

using namespace std;

class AccountStorage {
private:
    vector<Account> activeAccounts;
    vector<Account> deletedAccounts;
    static int nextId;

public:
    AccountStorage() = default;

    void InsertAccount(const Account& account) {
        Account newAccount = account;
        newAccount.setAccountId(nextId++);
        activeAccounts.push_back(newAccount);
    }

    Account* GetAccountById(int accountId) {
        for (auto& account : activeAccounts) {
            if (account.getAccountId() == accountId) {
                return &account;
            }
        }
        
        for (auto& account : deletedAccounts) {
            if (account.getAccountId() == accountId) {
                return &account;
            }
        }
        
        return nullptr;
    }
    bool IsAccountDeleted(int accountId) const {
        for (const auto& account : deletedAccounts) {
            if (account.getAccountId() == accountId) {
                return true;
            }
        }
        return false;
    }

    bool DeleteAccountById(int accountId) {
        for (auto it = activeAccounts.begin(); it != activeAccounts.end(); ++it) {
            if (it->getAccountId() == accountId) {
                deletedAccounts.push_back(*it);
                activeAccounts.erase(it);
                return true;
            }
        }
        return false;
    }

    bool RestoreAccount(int accountId) {
        for (auto it = deletedAccounts.begin(); it != deletedAccounts.end(); ++it) {
            if (it->getAccountId() == accountId) {
                activeAccounts.push_back(*it);
                deletedAccounts.erase(it);
                return true;
            }
        }
        return false;
    }

    void DisplayAllAccounts() const {
        cout << "Active Accounts:\n";
        for (const auto& account : activeAccounts) {
            account.printAccount();
        }

        cout << "\nDeleted Accounts:\n";
        for (const auto& account : deletedAccounts) {
            account.printAccount();
        }
    }
};

int AccountStorage::nextId = 1;