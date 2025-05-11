#pragma once

#include <iostream>
#include <string>
#include "../Storage/PaymentRepository.h"
#include "../Storage/IRepository.h"
#include "../Models/Payment.h"
using namespace std;

struct CreatePaymentRequest
{
    int accountId{};
    double amount{};

    CreatePaymentRequest() = default;

    CreatePaymentRequest(int accountId, double amount)
        : accountId(accountId), amount(amount) {}
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
    IRepository<Payment>& PaymentRepository;

public:
    explicit CreatePaymentHandler(IRepository<Payment>& storage)
        : PaymentRepository(storage) {}

    CreatePaymentResponse Handle(const CreatePaymentRequest& request)
    {
        if (request.amount <= 0)
        {
            cout << "Error: Payment amount must be greater than 0.\n";
            return CreatePaymentResponse("Payment amount must be greater than 0.");
        }

        try
        {
            Payment newPayment(request.accountId, request.amount, "created");
            PaymentRepository.Insert(newPayment);
            return CreatePaymentResponse(newPayment, "Payment created successfully.");
        }
        catch (const invalid_argument& e)
        {
            cout << "Error: " << e.what() << '\n';
            return CreatePaymentResponse("Invalid payment method ID.");
        }
    }
};
