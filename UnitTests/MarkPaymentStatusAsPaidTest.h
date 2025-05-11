#include <iostream>

#include "../Features/MarkPaymentStatusAsPaid.h"

class MarkPaymentStatusAsPaidTest
{
public:
    static void mark(int id) {
        PaymentRepository storage;

        MarkPaymentStatusAsPaidHandler handler(storage);

        MarkPaymentStatusAsPaidRequest request(id);

        MarkPaymentStatusAsPaidResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};