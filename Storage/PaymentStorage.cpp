#include <iostream> 
#include <vector>
#include <Payment.cpp>

using namespace std; 

class PaymentStorage
{
private:
    vector<Payment> payments;

public:
    void InsertPayment(const Payment &payment)
    {
        payments.push_back(payment);
    }

    Payment* GetPaymentById(int paymentId)
    {
        for (auto &payment : payments)
        {
            if (payment.GetPaymentId() == paymentId)
            {
                return &payment;
            }
        }
        return nullptr;
    }


    bool UpdatePayment(int paymentId, double newAmount, const string &newStatus)
    {
        for (auto &payment : payments)
        {
            if (payment.GetPaymentId() == paymentId)
            {
                payment.SetAmount(newAmount);
                payment.SetStatus(newStatus);
                cout << "Payment updated.\n";
                return true;
            }
        }
        cout << "Payment not found.\n";
        return false;
    }

    bool DeletePayment(int paymentId)
    {
        for (auto it = payments.begin(); it != payments.end(); ++it)
        {
            if (it->GetPaymentId() == paymentId)
            {
                payments.erase(it);
                cout << "Payment deleted.\n";
                return true;
            }
        }
        cout << "Payment not found.\n";
        return false;
    }
    
    void DisplayAllPayments() const
    {
        if (payments.empty())
        {
            cout << "No payments stored.\n";
            return;
        }

        for (auto payment : payments)
        {
            payment.Display();
        }
    }
};