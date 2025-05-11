#pragma once

#include <iostream>
#include <string>
#include "../Models/Account.h"
#include "../Storage/IRepository.h"
#include "../Storage/AccountRepository.h"

using namespace std;

struct GetAccountRequest {
    int accountId;
    GetAccountRequest(int id) : accountId(id) {}
};

struct GetAccountResponse {
    Account account;
    string message;

    GetAccountResponse(const Account _account, const string& msg)
        : account(_account), message(msg) {}

    explicit GetAccountResponse(const string& msg)
        : account(Account()), message(msg) {}
};

class GetAccountHandler {
private:
    IRepository<Account>& accountStorage;

public:
    explicit GetAccountHandler(IRepository<Account>& storage) : accountStorage(storage) {}

    GetAccountResponse handle(const GetAccountRequest& request) {
        Account* result = accountStorage.GetById(request.accountId);
        
        if (result != nullptr) {
            return GetAccountResponse(*result, "Account found.");
        } else {
            return GetAccountResponse("Account not found.");
        }
    }
};