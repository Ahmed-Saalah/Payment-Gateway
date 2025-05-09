#include <iostream>
#include <string>
#include "../Models/Refund.cpp"
#include "../Storage/RefundStorage.cpp"

using namespace std;

struct GetRefundByIdRequest
{
    int RefundId;
};

struct GetPaymentByIdResponse
{
    bool Found;
    Refund RefundResult;
    string Message;

    GetPaymentByIdResponse(bool found, const Refund& refund, const string& message)
        : Found(found), RefundResult(refund), Message(message) {}
};

class GetRefundById
{
private:
    RefundStorage &refundStorage;

public:
    GetRefundById(RefundStorage &storage) : refundStorage(storage) {}

    GetPaymentByIdResponse Handle(const GetRefundByIdRequest &request)
    {
        Refund* result = refundStorage.GetRefundById(request.RefundId);
        if (result != nullptr)
        {
            return {true, *result, "Refund found."};
        }
        else
        {
            return {false, Refund(), "Refund not found."};
        }
    }
};
