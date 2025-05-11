#include <iostream>

#include "../Features/CreateRefund.h"

using namespace std;

class CreateRefundTest {
public:
    static void Create(int PaymentId) {
        RefundRepository refundStorage;
        PaymentRepository paymentStorage;
        CreateRefundHandler handler(refundStorage, paymentStorage);

        CreateRefundRequest request(PaymentId, 6, "Dummy reason");
        
        CreateRefundResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        response.refund.Display();
    }
};
