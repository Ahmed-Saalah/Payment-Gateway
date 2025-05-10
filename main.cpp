#include <iostream>

#include "UnitTests/CreatePaymentTest.h"
#include "UnitTests/GetPaymentByIdTest.h"
#include "UnitTests/DeletePaymentTest.h"

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

    
    return 0;
}