#pragma once
#include "../Features/CreateAccount.h"

class CreateAccountTest {
public:
    static AccountStorage storage; 
    
    static void Create() {
        CreateAccountRequest request("Ahmed", "password123");
        CreateAccountMediator handler(storage);
        CreateAccountResponse response = handler.CreateAccount(request);

        cout << response.message << endl;
        response.AccountResult.printAccount();
    }
};

AccountStorage CreateAccountTest::storage; 