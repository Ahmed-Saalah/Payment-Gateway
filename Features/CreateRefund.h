#include <iostream>
#include <string>
#include <ctime>

#include "Refund.h"
#include "Payment.h"
#include "RefundStorage.h"
#include "PaymentStorage.h"

using namespace std;

struct CreateRefundRequest
{
    int PaymentId;
    double Amount;
    string Reason;

    CreateRefundRequest(int paymentId, double amount, const string& reason)
        : PaymentId(paymentId), Amount(amount), Reason(reason) {}
};

struct CreateRefundResponse
{
    Refund RefundResult;
    bool Success;
    string Message;

    CreateRefundResponse(const Refund& refund, bool success, const string& message)
        : RefundResult(refund), Success(success), Message(message) {}
};

class CreateRefund
{
private:
    RefundStorage& refundStorage;
    PaymentStorage& paymentStorage;

public:
    CreateRefund(RefundStorage& rs, PaymentStorage& ps)
        : refundStorage(rs), paymentStorage(ps) {}

    CreateRefundResponse Handle(const CreateRefundRequest& request)
    {
        Payment* payment = paymentStorage.GetPaymentById(request.PaymentId);
        if (payment == nullptr)
        {
            return CreateRefundResponse(Refund(), false, "Payment not found.");
        }

        if (payment->GetStatus() != "paid")
        {
            return CreateRefundResponse(Refund(), false, "Refund can only be issued for paid payments.");
        }

        if (request.Amount <= 0 || request.Amount > payment->GetAmount())
        {
            return CreateRefundResponse(Refund(), false, "Invalid refund amount.");
        }

        time_t now = time(0);
        string timestamp = ctime(&now);
        timestamp.pop_back(); 

        Refund newRefund(request.PaymentId, request.Amount, request.Reason, timestamp, "created");
        refundStorage.InsertRefund(newRefund);

        return CreateRefundResponse(newRefund, true, "Refund created successfully.");
    }
};
