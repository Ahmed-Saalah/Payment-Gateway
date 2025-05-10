#include <iostream>

#include "../Features/GetPaymentById.h"

using namespace std;

class GetPaymentByIdTest {
public:
    static void Get() {
        PaymentStorage storage;
        
        GetPaymentHandler handler(storage);

        GetPaymentRequest request(1);
        
        GetPaymentResponse response = handler.Handle(request);
        
        response.payment.Display();
    }
};
