#include <iostream>
#include <string>

#include "../Models/Payment.h"
#include "../Storage/PaymentStorage.h"

using namespace std;

struct DeletePaymentRequest
{
    int PaymentId;
    DeletePaymentRequest(int id) : PaymentId(id) {}
};

struct DeletePaymentResponse
{
    bool success;
    string message;

    DeletePaymentResponse(bool status, const string& msg)
        : success(status), message(msg) {}
};

class DeletePaymentHandler
{
private:
    PaymentStorage &paymentStorage;

public:
    DeletePaymentHandler(PaymentStorage &storage) : paymentStorage(storage) {}

    DeletePaymentResponse Handle(const DeletePaymentRequest &request)
    {
        bool deleted = paymentStorage.DeletePayment(request.PaymentId);

        if (deleted)
        {
            return {true, "Payment deleted successfully."};
        }
        else
        {
            return {false, "Payment not found."};
        }
    }
};
