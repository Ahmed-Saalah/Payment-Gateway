#include <iostream>

#include "../Features/GetRefundById.h"

using namespace std;

class GetRefundByIdTest {
public:
    static void Get() {
        RefundRepository storage;
        
        GetRefundByIdHandler handler(storage);

        GetRefundByIdRequest request(1);
        
        GetRefundResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        
        response.refund.Display();
    }
};
