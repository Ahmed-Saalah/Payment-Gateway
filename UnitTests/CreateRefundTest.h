#include <iostream>

#include "../Features/CreateRefund.h"

using namespace std;

class CreateRefundTest {
public:
    static void Create() {
        RefundRepository refundStorage;
        PaymentRepository paymentStorage;
        CreateRefundHandler handler(refundStorage, paymentStorage);

        CreateRefundRequest request(1, 6, "Dummy reason");
        
        CreateRefundResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        response.refund.Display();
    }
};
