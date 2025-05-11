#pragma once
#include "../Features/DeleteAccount.h"
#include "CreateAccountTest.h" 

class DeleteAccountTest {
public:
    static void Delete(int id) {
        DeleteAccountHandler handler(CreateAccountTest::storage);
        DeleteAccountRequest request(id); 
        DeleteAccountResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};