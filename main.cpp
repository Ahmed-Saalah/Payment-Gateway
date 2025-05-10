#include <iostream>

#include "UnitTests/CreatePaymentTest.h"
#include "UnitTests/GetPaymentByIdTest.h"
#include "UnitTests/DeletePaymentTest.h"
#include "UnitTests/CreateRefundTest.h"
#include "UnitTests/DeleteRefundTest.h"
#include "UnitTests/GetRefundByIdTest.h"

using namespace std;

int main() 
{

    #pragma region Payment 
    CreatePaymentTest::Create();

    cout << endl;
    
    GetPaymentByIdTest::Get();
    
    cout << endl;

    DeletePaymentTest::Delete();

    cout << endl;

    GetPaymentByIdTest::Get();
    #pragma endregion Payment


    cout << endl;
    
    #pragma region Refund
    CreateRefundTest::Create(); // Refunded
    CreateRefundTest::Create(); // Amount exeded
    
    DeleteRefundTest::Delete();

    cout << endl;
    
    GetRefundByIdTest::Get();
    
    #pragma endregion Refund
    
    return 0;
}