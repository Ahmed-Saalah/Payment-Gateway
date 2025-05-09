#include <iostream>
#include <string>

using namespace std;

class Payment
{
private:
    int PaymentId;
    int AccountId;
    double Amount;
    int PaymentMethodId;
    string Status;
    string Timestamp;

    static int Ids;

public:
    Payment(int accountId, double amount, int paymentMethodId, string status) 
    : PaymentId(Ids++), AccountId(accountId), Amount(amount), PaymentMethodId(paymentMethodId), Status(status) {}
    
    int GetPaymentId() {return PaymentId;}
    string GetStatus() {return Status; }
    double GetAmount() {return Amount; }
    void SetAmount(double amount) { Amount = amount; }
    void SetStatus(const string &status) { Status = status; }

    void Display()
    {
        cout << "Payment Created: \n"
                  << "PaymentId: " << PaymentId << '\n'
                  << "AccountId: " << AccountId << "\n"
                  << "Amount: " << Amount << "\n"
                  << "PaymentMethodId: " << PaymentMethodId << "\n"
                  << "Status: " << Status << "\n";
    }
};

int Payment::Ids = 1;

class PaymentMethod {
public:
    int PaymentMethodId;
    virtual ~PaymentMethod() {}

    virtual void processPayment(double amount) = 0;
    virtual string getMethodName() const = 0;
    virtual int getMethodId() const = 0;
};

class CreditCardPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "[CreditCard] Processing payment of $" << amount << "\n";
    }

    string getMethodName() const override {
        return "Credit Card";
    }
    int getMethodId() const override {
        return 1;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "[PayPal] Processing payment of $" << amount << " through PayPal\n";
    }

    string getMethodName() const override {
        return "PayPal";
    }
    int getMethodId() const override {
        return 2;
    }
};

class CashPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "[Cash] Processing payment of $" << amount << " through cash\n";
    }

    string getMethodName() const override {
        return "cash";
    }
    int getMethodId() const override {
        return 3;
    }
};