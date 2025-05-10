#pragma once

#include <iostream>
#include <string>
#include "../Models/Payment.h"
#include "../Storage/PaymentStorage.h"

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
    PaymentStorage& paymentStorage;

public:
    explicit GetPaymentHandler(PaymentStorage& storage) : paymentStorage(storage) {}

    GetPaymentResponse Handle(const GetPaymentRequest& request) 
    {
        Payment* result = paymentStorage.GetPaymentById(request.PaymentId);
        
        if (result != nullptr) {
            return GetPaymentResponse(*result, "Payment found.");
        } else {
            return GetPaymentResponse("Payment not found.");
        }
    }
};
