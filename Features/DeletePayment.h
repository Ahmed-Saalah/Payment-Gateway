#include <iostream>
#include <string>

#include "Payment.h"
#include "PaymentStorage.h"
#include "PaymentStorage.h"

using namespace std;

struct DeletePaymentRequest
{
    int PaymentId;
};

struct DeletePaymentResponse
{
    bool Success;
    string Message;
};

class DeletePayment
{
private:
    PaymentStorage &paymentStorage;

public:
    DeletePayment(PaymentStorage &storage) : paymentStorage(storage) {}

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
