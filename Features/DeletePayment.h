#include <iostream>
#include <string>

#include "../Models/Payment.h"
#include "../Storage/PaymentRepository.h"
#include "../Storage/IRepository.h"

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
    IRepository<Payment>& PaymentRepository;

public:
    DeletePaymentHandler(IRepository<Payment>& storage) : PaymentRepository(storage) {}

    DeletePaymentResponse Handle(const DeletePaymentRequest &request)
    {
        bool deleted = PaymentRepository.Delete(request.PaymentId);

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
