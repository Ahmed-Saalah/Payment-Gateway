#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "../Models/Account.h"
#include "IRepository.h"

using namespace std;

class AccountStorage : public IRepository<Account> {
private:
    vector<Account> accounts;

public:
    void Insert(const Account& account) override {
        accounts.push_back(account);
    }

    Account* GetById(int id) override {
        for (auto& account : accounts) {
            if (account.getAccountId() == id) {
                return &account;
            }
        }
        return nullptr;
    }

    bool Update(int id, Account& updatedAccount) override {
        for (auto& account : accounts) {
            if (account.getAccountId() == id) {
                account.setHandlerName(updatedAccount.getHandlerName());
                account.setPassword(updatedAccount.getPassword());
                return true;
            }
        }
        return false;
    }

    bool Delete(int id) override {
        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->getAccountId() == id) {
                accounts.erase(it);
                return true;
            }
        }
        return false;
    }

    void DisplayAll() const override {
        if (accounts.empty()) {
            cout << "No accounts stored.\n";
            return;
        }

        for (auto& account : accounts) {
            account.Display();
        }
    }

    // void SeedData() {
    //     accounts.push_back(Account("Ahmed Salah", "pas1"));
    //     accounts.push_back(Account("Sara Mohamed", "asc@1"));
    //     accounts.push_back(Account("Kareem Mostafa", "pass"));
    // }
};
