#include <iostream>

#include "../Features/GetRefundById.h"

using namespace std;

class GetRefundByIdTest {
public:
    static void Get(int id) {
        RefundRepository storage;
        
        GetRefundByIdHandler handler(storage);

        GetRefundByIdRequest request(id);
        
        GetRefundResponse response = handler.Handle(request);
        
        cout << response.message << endl;
        
        response.refund.Display();
    }
};
