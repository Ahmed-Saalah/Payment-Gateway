#include <iostream>

#include "../Features/DeletePayment.h"

class DeletePaymentTest
{
public:
    static void Delete(int id) {
        PaymentRepository storage;

        DeletePaymentHandler handler(storage);

        DeletePaymentRequest request(id);

        DeletePaymentResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};