#include <iostream>
#include <string>

using namespace std;

class Refund {
private:
    int RefundId;
    int PaymentId;
    double Amount;
    string Reason;
    string Timestamp;
    string Status; // e.g., "created", "completed", "failed"

    static int Ids;

public:
    Refund() = default;

    Refund(int paymentId, double amount, const string& reason,
           const string& timestamp, const string& status)
        : RefundId(Ids++), PaymentId(paymentId), Amount(amount),
          Reason(reason), Timestamp(timestamp), Status(status) {}

    int getRefundId() const { return RefundId; }
    int getPaymentId() const { return PaymentId; }
    double getAmount() const { return Amount; }
    string getReason() const { return Reason; }
    string getTimestamp() const { return Timestamp; }
    string getStatus() const { return Status; }

    void setStatus(const string& status) { Status = status; }

    void Display() const {
        cout << "Refund ID: " << RefundId << "\n"
                  << "Payment ID: " << PaymentId << "\n"
                  << "Amount: " << Amount << "\n"
                  << "Reason: " << Reason << "\n"
                  << "Timestamp: " << Timestamp << "\n"
                  << "Status: " << Status << "\n";
    }
};

int Refund::Ids = 1;
