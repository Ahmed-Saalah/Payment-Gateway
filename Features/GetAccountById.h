#pragma once

#include <iostream>
#include <string>
#include "../Models/Account.h"
#include "../Storage/AccountStorage.h"

using namespace std;

struct GetAccountRequest {
    int accountId;
    GetAccountRequest(int id) : accountId(id) {}
};

struct GetAccountResponse {
    Account account;
    string message;
    bool isDeleted; 

    GetAccountResponse(const Account& acc, const string& msg, bool deleted)
        : account(acc), message(msg), isDeleted(deleted) {}

    explicit GetAccountResponse(const string& msg)
        : account(Account()), message(msg), isDeleted(false) {}
};

class GetAccountHandler {
private:
    AccountStorage& accountStorage;

public:
    explicit GetAccountHandler(AccountStorage& storage) : accountStorage(storage) {}

    GetAccountResponse handle(const GetAccountRequest& request) {
        Account* result = accountStorage.GetAccountById(request.accountId);
        
        if (result != nullptr) {
            bool isDeleted = accountStorage.IsAccountDeleted(request.accountId);
            string statusMessage = isDeleted ? "Account found (deleted)." : "Account found.";
            
            return GetAccountResponse(*result, statusMessage, isDeleted);
        } else {
            return GetAccountResponse("Account not found.");
        }
    }
};