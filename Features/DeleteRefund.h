#include <iostream>
#include <string>

#include "../Models/Refund.h"
#include "../Storage/RefundRepository.h"
#include "../Storage/IRepository.h"

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
    IRepository<Refund> &RefundRepository;

public:
    DeleteRefundHandler(IRepository<Refund> &storage) : RefundRepository(storage) {}

    DeleteRefundResponse Handle(const DeleteRefundRequest &request)
    {
        bool deleted = RefundRepository.Delete(request.RefundId);
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