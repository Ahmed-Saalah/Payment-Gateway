#include <iostream>
#include <string>
#include <ctime>

#include "../Models/Refund.h"
#include "../Models/Payment.h"
#include "../Storage/RefundStorage.h"
#include "../Storage/PaymentStorage.h"

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
    Refund refund;
    string message;

    CreateRefundResponse(const Refund& refund, const string& msg)
        : refund(refund), message(msg) {}

    explicit CreateRefundResponse(const string& msg)
        : refund(Refund()), message(msg) {}
};

class CreateRefundHandler
{
private:
    RefundStorage& refundStorage;
    PaymentStorage& paymentStorage;

public:
    CreateRefundHandler(RefundStorage& rs, PaymentStorage& ps)
        : refundStorage(rs), paymentStorage(ps) {}

    CreateRefundResponse Handle(const CreateRefundRequest& request)
    {
        Payment* payment = paymentStorage.GetPaymentById(request.PaymentId);
        if (payment == nullptr)
        {
            return CreateRefundResponse("Payment not found.");
        }

        if (payment->GetStatus() != "paid")
        {
            return CreateRefundResponse("Refund can only be issued for paid payments.");
        }

        if (request.Amount <= 0 || request.Amount > payment->GetAmount())
        {
            return CreateRefundResponse("Invalid refund amount.");
        }

        Refund newRefund(request.PaymentId, request.Amount, request.Reason, "created");
        refundStorage.InsertRefund(newRefund);

        paymentStorage.UpdatePayment(payment->GetPaymentId(), payment->GetAmount() - request.Amount, payment->GetStatus());
        return CreateRefundResponse(newRefund, "Refund created successfully.");
    }
};
