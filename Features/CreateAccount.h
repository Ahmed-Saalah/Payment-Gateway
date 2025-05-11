#pragma once
#include <string>
#include "../Storage/AccountStorage.h"
#include "../Models/Account.h"

using namespace std;

class CreateAccountRequest {
public:
    string HandlerName;
    string Password;

    CreateAccountRequest(string handlerName, string password)
        : HandlerName(handlerName), Password(password) {}
};

class CreateAccountResponse {
public:
    string message;
    Account AccountResult;

    CreateAccountResponse(const string& msg, const Account& account)
        : message(msg), AccountResult(account) {}
};

class CreateAccountMediator {
private:
    AccountStorage& accountStorage;

public:
    CreateAccountMediator(AccountStorage& storage) : accountStorage(storage) {}

    CreateAccountResponse CreateAccount(const CreateAccountRequest& request) {
        Account newAccount(request.HandlerName, request.Password);
        accountStorage.InsertAccount(newAccount);
        return CreateAccountResponse("Account created successfully.", newAccount);
    }
};
