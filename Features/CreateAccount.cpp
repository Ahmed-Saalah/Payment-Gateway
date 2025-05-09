#include <iostream>
#include <string>

#include <Account.cpp>
#include <AccountStorage.cpp>

using namespace std;

class CreateAccountRequest
{
public:
    string HandlerName; 
    string Password;

    CreateAccountRequest(string handlerName , string password) 
        : HandlerName(handlerName) , Password(password){}
};

class CreateAccountResponse
{ 
public:
    Account AccountResult;

    CreateAccountResponse(Account Account) : AccountResult(Account) {}
};

class CreateAccountMediator
{
private:
    AccountStorage &AccountStorage;

public:
    CreateAccountMediator(AccountStorage &storage) : AccountStorage(storage) {}

    CreateAccountResponse CreateAccount(const CreateAccountRequest &request)
    {
        
        Account newAccount(request.HandlerName, requset.Password );

        AccountStorage.InsertAccount(newAccount);

        return CreateAccountResponse(newAccount);
    }
};