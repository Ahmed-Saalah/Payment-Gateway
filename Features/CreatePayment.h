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
    IRepository<Payment>& paymentRepository;

    string validate(const CreatePaymentRequest& request) {
        if (request.accountId <= 0) {
            return "Error: Invalid account ID.";
        }

        if (request.amount <= 0) {
            return "Error: Payment amount must be greater than 0.";
        }

        // TODO: Add real account existence validation here.

        return "";
    }

public:
    explicit CreatePaymentHandler(IRepository<Payment>& storage)
        : paymentRepository(storage) {}

    CreatePaymentResponse Handle(const CreatePaymentRequest& request)
    {
        string validationResult = validate(request);

        if (!validationResult.empty()) {
            return CreatePaymentResponse(validationResult);
        }

        try {
            Payment newPayment(request.accountId, request.amount, "created");
            paymentRepository.Insert(newPayment);
            return CreatePaymentResponse(newPayment, "Payment created successfully.");
        }
        catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << '\n';
            return CreatePaymentResponse("Invalid payment data.");
        }
    }
};
