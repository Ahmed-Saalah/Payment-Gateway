#include <iostream>
#include <string>
#include "../Models/Payment.cpp"
#include "../Storage/PaymentStorage.cpp"

using namespace std;

struct GetPaymentByIdRequest
{
    int PaymentId;
};

struct GetPaymentByIdResponse
{
    bool Found;
    Payment PaymentResult;
    string Message;

    GetPaymentByIdResponse(bool found, const Payment& payment, const string& message)
        : Found(found), PaymentResult(payment), Message(message) {}
};

class GetPaymentById
{
private:
    PaymentStorage &paymentStorage;

public:
    GetPaymentById(PaymentStorage &storage) : paymentStorage(storage) {}

    GetPaymentByIdResponse Handle(const GetPaymentByIdRequest &request)
    {
        Payment* result = paymentStorage.GetPaymentById(request.PaymentId);
        if (result != nullptr)
        {
            return {true, *result, "Payment found."};
        }
        else
        {
            return {false, Payment(0, 0, 0, "Not Found"), "Payment not found."};
        }
    }
};
