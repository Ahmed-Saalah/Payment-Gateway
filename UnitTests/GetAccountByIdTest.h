#pragma once
#include "../Features/GetAccountById.h"
#include "CreateAccountTest.h"   

class GetAccountByIdTest {
public:
    static void Get(int id) {
        GetAccountHandler handler(CreateAccountTest::storage);
        GetAccountRequest request(id); 
        GetAccountResponse response = handler.handle(request);

        cout << response.message << endl;
        if (response.account.getAccountId() != -1) {
            response.account.Display();
        }
    }
};