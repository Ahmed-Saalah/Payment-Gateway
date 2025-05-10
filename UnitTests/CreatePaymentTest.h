#include <iostream>

#include "../Features/CreatePayment.h"

using namespace std;

class CreatePaymentTest {
public:
    static void Create() {
        PaymentStorage storage;
        CreatePaymentHandler handler(storage);

        CreatePaymentRequest request(101, 10, 2);
        
        CreatePaymentResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        response.payment.Display();
    }
};
