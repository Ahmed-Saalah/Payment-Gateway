#pragma once
#include <string>
#include "../Models/Account.h"
#include "../Storage/IRepository.h"
#include "../Storage/AccountRepository.h"

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
    IRepository<Account>& accountStorage;

public:
    CreateAccountMediator(IRepository<Account>&  storage) : accountStorage(storage) {}

    CreateAccountResponse CreateAccount(const CreateAccountRequest& request) {
        Account newAccount(request.HandlerName, request.Password);
        accountStorage.Insert(newAccount);
        return CreateAccountResponse("Account created successfully.", newAccount);
    }
};
