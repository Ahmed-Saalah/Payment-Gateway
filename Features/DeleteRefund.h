#include <iostream>
#include <string>

#include "../Models/Refund.h"
#include "../Storage/RefundStorage.h"

using namespace std;


struct DeleteRefundRequest
{
    int RefundId;
    DeleteRefundRequest(int id) : RefundId(id) {}
};

struct DeleteRefundResponse
{
    bool succes;
    string message;

    DeleteRefundResponse(bool status, const string& msg)
        : succes(status), message(msg) {}
};

class DeleteRefundHandler
{
private:
    RefundStorage &refundStorage;

public:
    DeleteRefundHandler(RefundStorage &storage) : refundStorage(storage) {}

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