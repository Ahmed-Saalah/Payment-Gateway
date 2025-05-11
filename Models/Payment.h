#pragma once

#include <string>

using namespace std;

class Payment
{
private:
    int PaymentId;
    int AccountId;
    double Amount;
    string Status;

    static int identity;

public:
    Payment() : PaymentId(-1) {}

    Payment(int accountId, double amount, string status) 
    : PaymentId(identity++), AccountId(accountId), Amount(amount), Status(status) {}
    
   Payment(const Payment& other)
    : PaymentId(other.PaymentId), AccountId(other.AccountId),
      Amount(other.Amount), Status(other.Status) {}

    int GetPaymentId() const { return PaymentId; }
    string GetStatus() const { return Status; }
    double GetAmount() const { return Amount; }

    void SetAmount(double amount)  { Amount = amount; }
    void SetStatus(const string &status) { Status = status; }

    void Display() const
    {
        cout  << "Payment: \n"
            << "PaymentId: " << PaymentId << '\n'
            << "AccountId: " << AccountId << "\n"
            << "Amount: " << Amount << "\n"
            << "Status: " << Status << "\n";
    }
};

int Payment::identity = 1;