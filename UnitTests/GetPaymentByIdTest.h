#include <iostream>

#include "../Features/GetPaymentById.h"

using namespace std;

class GetPaymentByIdTest {
public:
    static void Get(int id) {
        PaymentRepository storage;
        
        GetPaymentHandler handler(storage);

        GetPaymentRequest request(id);
        
        GetPaymentResponse response = handler.Handle(request);
        
        cout << response.Message << endl;
        
        if (response.payment.GetPaymentId() != -1) {
            response.payment.Display();
        }
    }
};
