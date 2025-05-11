#include <iostream>

#include "../Features/CreatePayment.h"

using namespace std;

class CreatePaymentTest {
public:
    static void Create() {
        PaymentRepository storage;
        
        CreatePaymentHandler handler(storage);

        CreatePaymentRequest request(1, 10);
        
        CreatePaymentResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        response.payment.Display();
    }
};
