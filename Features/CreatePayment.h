#pragma once

#include <iostream>
#include <string>
#include "../Storage/PaymentStorage.h"
#include "../Models/Payment.h"
using namespace std;

struct CreatePaymentRequest
{
    int accountId{};
    double amount{};
    int paymentMethodId{};

    CreatePaymentRequest() = default;

    CreatePaymentRequest(int accountId, double amount, int paymentMethodId)
        : accountId(accountId), amount(amount), paymentMethodId(paymentMethodId) {}
};

struct CreatePaymentResponse
{
    Payment payment;
    string message;

    CreatePaymentResponse() = default;

    CreatePaymentResponse(const Payment& payment, const string& msg)
        : payment(payment), message(msg) {}

    explicit CreatePaymentResponse(const string& msg)
        : payment(Payment()), message(msg) {}
};

class CreatePaymentHandler
{
private:
    PaymentStorage& paymentStorage;

    PaymentMethods GetPaymentMethod(int methodId) const
    {
        switch (methodId)
        {
            case 1: return PaymentMethods::Cash;
            case 2: return PaymentMethods::CreditCard;
            case 3: return PaymentMethods::PayPal;
            default: throw invalid_argument("Invalid payment method ID.");
        }
    }

public:
    explicit CreatePaymentHandler(PaymentStorage& storage)
        : paymentStorage(storage) {}

    CreatePaymentResponse Handle(const CreatePaymentRequest& request)
    {
        if (request.amount <= 0)
        {
            cout << "Error: Payment amount must be greater than 0.\n";
            return CreatePaymentResponse("Payment amount must be greater than 0.");
        }

        try
        {
            PaymentMethods method = GetPaymentMethod(request.paymentMethodId);
            Payment newPayment(request.accountId, request.amount, method, "Created");
            paymentStorage.InsertPayment(newPayment);
            return CreatePaymentResponse(newPayment, "Payment created successfully.");
        }
        catch (const invalid_argument& e)
        {
            cout << "Error: " << e.what() << '\n';
            return CreatePaymentResponse("Invalid payment method ID.");
        }
    }
};
