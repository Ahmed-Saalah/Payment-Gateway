#include <iostream>

#include "../Features/GetPaymentById.h"

using namespace std;

class GetPaymentByIdTest {
public:
    static void Get() {
        PaymentRepository storage;
        
        GetPaymentHandler handler(storage);

        GetPaymentRequest request(1);
        
        GetPaymentResponse response = handler.Handle(request);
        
        cout << response.Message << endl;
        
        if (response.payment.GetPaymentId() != -1) {
            response.payment.Display();
        }
    }
};
