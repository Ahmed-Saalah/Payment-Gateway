#include <iostream>
#include <string>

#include "../Models/Payment.h"
#include "../Storage/PaymentRepository.h"
#include "../Storage/IRepository.h"

using namespace std;

struct MarkPaymentStatusAsPaidRequest
{
    int PaymentId;
    MarkPaymentStatusAsPaidRequest(int id) : PaymentId(id) {}
};

struct MarkPaymentStatusAsPaidResponse
{
    string message;

    MarkPaymentStatusAsPaidResponse(const string& msg)
        : message(msg) {}
};

class MarkPaymentStatusAsPaidHandler
{
private:
    IRepository<Payment>& PaymentRepository;

    string validate(const MarkPaymentStatusAsPaidRequest& request) {
        if (request.PaymentId <= 0) {
            return "Error: Invalid account ID.";
        }


        return "";
    }

public:
    MarkPaymentStatusAsPaidHandler(IRepository<Payment>& storage) : PaymentRepository(storage) {}

    MarkPaymentStatusAsPaidResponse Handle(const MarkPaymentStatusAsPaidRequest &request)
    {
        auto validationResult = validate(request);

         if (!validationResult.empty()) {
            return MarkPaymentStatusAsPaidResponse(validationResult);
        }
        
        Payment* payment = PaymentRepository.GetById(request.PaymentId);

        if (payment == nullptr) {
            return MarkPaymentStatusAsPaidResponse("Payment not found");
        }

        payment->SetStatus("paid");
        
        PaymentRepository.Update(payment->GetPaymentId(), *payment);

        return MarkPaymentStatusAsPaidResponse("Updated successfully");
    }
};
