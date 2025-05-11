#pragma once

#include <iostream>
#include <string>

using namespace std;

class Refund {
private:
    int RefundId;
    int PaymentId;
    double Amount;
    string Reason;
    string Status;

    static int Ids;

public:
    Refund(): RefundId(-1) {}

    Refund(int paymentId, double amount, const string& reason, const string& status)
        : RefundId(Ids++), PaymentId(paymentId), Amount(amount), Reason(reason), Status(status) {}


    Refund(const Refund& other) :
        RefundId(other.RefundId), PaymentId(other.PaymentId), Amount(other.Amount),
        Reason(other.Reason), Status(other.Status) {}


    int getRefundId() const { return RefundId; }
    int getPaymentId() const { return PaymentId; }
    double getAmount() const { return Amount; }
    string getReason() const { return Reason; }
    string getStatus() const { return Status; }

    void setStatus(const string& status) { Status = status; }

    void Display() const {
        if (RefundId == -1) return;
        
        cout << "Refund ID: " << RefundId << "\n"
                  << "Payment ID: " << PaymentId << "\n"
                  << "Amount: " << Amount << "\n"
                  << "Reason: " << Reason << "\n"
                  << "Status: " << Status << "\n";
    }
};

int Refund::Ids = 1;
