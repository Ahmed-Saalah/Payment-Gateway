#include <iostream>

#include "../Features/DeletePayment.h"

class DeletePaymentTest
{
public:
    static void Delete() {
        PaymentRepository storage;

        DeletePaymentHandler handler(storage);

        DeletePaymentRequest request(1);

        DeletePaymentResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};