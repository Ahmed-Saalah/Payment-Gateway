#include <iostream>

#include "UnitTests/CreatePaymentTest.h"
#include "UnitTests/GetPaymentByIdTest.h"

using namespace std;

int main() 
{
    CreatePaymentTest::Create();

    cout << endl;
    
    GetPaymentByIdTest::Get();
    
    return 0;
}