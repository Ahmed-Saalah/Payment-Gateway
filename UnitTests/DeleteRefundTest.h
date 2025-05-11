#include <iostream>

#include "../Features/DeleteRefund.h"

class DeleteRefundTest
{
public:
    static void Delete(int id) {
        RefundRepository storage;

        DeleteRefundHandler handler(storage);

        DeleteRefundRequest request(id);

        DeleteRefundResponse response = handler.Handle(request);

        cout << response.message << endl;
    }
};