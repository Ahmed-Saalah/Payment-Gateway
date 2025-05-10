#include <iostream>
#include <string>

#include "Account.h"
#include "AccountStorage.h"

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
    Account AccountResult;

    CreateAccountResponse(Account account) : AccountResult(account) {}
};

class CreateAccountMediator {
private:
    AccountStorage& accountStorage;

public:
    CreateAccountMediator(AccountStorage& storage) : accountStorage(storage) {}

    CreateAccountResponse CreateAccount(const CreateAccountRequest& request) {
        Account newAccount(request.HandlerName, request.Password);
        accountStorage.InsertAccount(newAccount);
        return CreateAccountResponse(newAccount);
    }
};
