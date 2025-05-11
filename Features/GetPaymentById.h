#pragma once

#include <iostream>
#include <string>
#include "../Models/Payment.h"
#include "../Storage/PaymentRepository.h"
#include "../Storage/IRepository.h"

using namespace std;

struct GetPaymentRequest {
    int PaymentId;
    GetPaymentRequest(int id) : PaymentId(id) {}
};

struct GetPaymentResponse {
    Payment payment;
    string Message;

    GetPaymentResponse(const Payment& payment, const string& message)
        : payment(payment), Message(message) {}

    explicit GetPaymentResponse(const string& msg)
        : payment(Payment()), Message(msg) {}
};

class GetPaymentHandler {
private:
    IRepository<Payment>& PaymentRepository;

public:
    explicit GetPaymentHandler(IRepository<Payment>& storage) : PaymentRepository(storage) {}

    GetPaymentResponse Handle(const GetPaymentRequest& request) 
    {
        Payment* result = PaymentRepository.GetById(request.PaymentId);
        
        if (result != nullptr) {
            return GetPaymentResponse(*result, "Payment found.");
        } else {
            return GetPaymentResponse("Payment not found.");
        }
    }
};
