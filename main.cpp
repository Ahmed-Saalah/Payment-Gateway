#include <iostream>

#include "UnitTests/CreatePaymentTest.h"
#include "UnitTests/GetPaymentByIdTest.h"
#include "UnitTests/DeletePaymentTest.h"
#include "UnitTests/CreateRefundTest.h"
#include "UnitTests/DeleteRefundTest.h"
#include "UnitTests/GetRefundByIdTest.h"
#include "UnitTests/CreateAccountTest.h"
#include "UnitTests/GetAccountByIdTest.h"
#include "UnitTests/DeleteAccountTest.h"
#include "UnitTests/MarkPaymentStatusAsPaidTest.h"

using namespace std;

int main() 
{


    #pragma region Account 
        // CreateAccountTest::Create();

        // cout << endl;
        
        // GetAccountByIdTest::Get(1);
        
        // cout << endl;

        // DeleteAccountTest::Delete(1);

        // cout << endl;

        // GetAccountByIdTest::Get(1);
        // cout << endl;
    #pragma endregion Account


    cout << endl;


    #pragma region Payment 
        // CreatePaymentTest::Create();

        // cout << endl;
        
        // GetPaymentByIdTest::Get(1);
        
        // cout << endl;

        // DeletePaymentTest::Delete(1);

        // cout << endl;

        // GetPaymentByIdTest::Get(1);
    // #pragma endregion Payment


    cout << endl;
    
    #pragma region Refund

        CreatePaymentTest::Create();
        cout << endl;

        CreateRefundTest::Create(); // !Paid
        cout << endl;
        
        MarkPaymentStatusAsPaidTest::mark(1);
        cout << endl;
        
        CreateRefundTest::Create(); // Refunded
        cout << endl;
        
        CreateRefundTest::Create(); // Amount exeded
        cout << endl;

        DeleteRefundTest::Delete(1); 
        cout << endl;

        
        GetRefundByIdTest::Get(1);
        cout << endl;
    
    #pragma endregion Refund
   
    return 0;
}