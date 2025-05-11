#include <iostream>
#include <string>
#include <ctime>

#include "../Models/Refund.h"
#include "../Models/Payment.h"
#include "../Storage/RefundRepository.h"
#include "../Storage/PaymentRepository.h"
#include "../Storage/IRepository.h"

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
    IRepository<Refund>& RefundRepository;
    IRepository<Payment>& PaymentRepository;

public:
    CreateRefundHandler(IRepository<Refund>& rs, IRepository<Payment>& ps)
        : RefundRepository(rs), PaymentRepository(ps) {}

    CreateRefundResponse Handle(const CreateRefundRequest& request)
    {
        Payment* payment = PaymentRepository.GetById(request.PaymentId);

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
        RefundRepository.Insert(newRefund);

        payment->SetStatus("refunded");
        payment->SetAmount(payment->GetAmount() - request.Amount);

        PaymentRepository.Update(payment->GetPaymentId(), *payment);

        return CreateRefundResponse(newRefund, "Refund created successfully.");
    }
};
