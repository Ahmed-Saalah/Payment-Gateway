#include <iostream>
#include <string>

#include "Refund.h"
#include "RefundStorage.h"

using namespace std;


struct DeleteRefundRequest
{
    int RefundId;
};

struct DeleteRefundResponse
{
    bool Success;
    string Message;
};

class DeleteRefund
{
private:
    RefundStorage &refundStorage;

public:
    DeleteRefund(RefundStorage &storage) : refundStorage(storage) {}

    DeleteRefundResponse Handle(const DeleteRefundRequest &request)
    {
        bool deleted = refundStorage.DeleteRefund(request.RefundId);
        if (deleted)
        {
            return {true, "Refund deleted successfully."};
        }
        else
        {
            return {false, "Refund not found."};
        }
    }
};