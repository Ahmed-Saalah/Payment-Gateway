#include <iostream>
#include <string>

#include <Payment.cpp>
#include <PaymentStorage.cpp>

using namespace std;

class CreatePaymentRequest
{
public:
    int AccountId;
    double Amount;
    int PaymentMethodId;

    CreatePaymentRequest(int accountId, double amount, int paymentMethodId)
        : AccountId(accountId), Amount(amount), PaymentMethodId(paymentMethodId) {}
};

class CreatePaymentResponse
{
public:
    Payment PaymentResult;

    CreatePaymentResponse(Payment payment) : PaymentResult(payment) {}
};

class CreatePaymentMediator
{
private:
    PaymentStorage &paymentStorage;

public:
    CreatePaymentMediator(PaymentStorage &storage) : paymentStorage(storage) {}

    CreatePaymentResponse CreatePayment(const CreatePaymentRequest &request)
    {
        if (request.Amount <= 0)
        {
            cout << "Error: Invalid payment amount.\n";
            return CreatePaymentResponse(Payment(0, 0, 0, "Failed"));
        }

        Payment newPayment(request.AccountId, request.Amount, request.PaymentMethodId, "Created");

        paymentStorage.InsertPayment(newPayment);

        return CreatePaymentResponse(newPayment);
    }
};