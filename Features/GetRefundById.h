#include <iostream>
#include <string>
#include "../Models/Refund.h"
#include "../Storage/RefundRepository.h"
#include "../Storage/IRepository.h"

using namespace std;

struct GetRefundByIdRequest
{
    int RefundId;
    GetRefundByIdRequest(int id) : RefundId(id) {}
};

struct GetRefundResponse
{
    Refund refund;
    string message;

    GetRefundResponse(const Refund& refund, const string& msg)
        : refund(refund), message(msg) {}

    explicit GetRefundResponse(const string& msg)
        : refund(Refund()), message(msg) {}
};

class GetRefundByIdHandler
{
private:
    IRepository<Refund> &RefundRepository;

public:
    GetRefundByIdHandler(IRepository<Refund> &storage) : RefundRepository(storage) {}

    GetRefundResponse Handle(const GetRefundByIdRequest &request)
    {
        Refund* result = RefundRepository.GetById(request.RefundId);

        if (result != nullptr)
        {
            return GetRefundResponse(*result, "Refund found.");
        }
        else
        {
            return GetRefundResponse("Refund not found.");
        }
    }
};
