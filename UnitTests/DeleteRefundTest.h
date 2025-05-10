#include <iostream>

#include "../Features/DeleteRefund.h"

class DeleteRefundTest
{
public:
    static void Delete() {
        RefundStorage storage;

        DeleteRefundHandler handler(storage);

        DeleteRefundRequest request(1);

        DeleteRefundResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};