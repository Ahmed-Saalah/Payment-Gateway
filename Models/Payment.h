#pragma once

#include <string>

using namespace std;

enum PaymentMethods {
    Cash,
    CreditCard,
    PayPal
};

class Payment
{
private:
    int PaymentId;
    int AccountId;
    double Amount;
    PaymentMethods PaymentMethod;
    string Status;
    string Timestamp;

    static int Ids;

    string PaymentMethodToString(PaymentMethods method) const {
        switch (method)
        {
            case Cash: return "Cash";
            case CreditCard: return "Credit Card";
            case PayPal: return "PayPal";
            default: return "Unknown";
        }
    }

public:
    Payment()
    : PaymentId(-1), AccountId(0), Amount(0.0),
      PaymentMethod(PaymentMethods::Cash), Status(""), Timestamp("") {}

    Payment(int accountId, double amount, PaymentMethods paymentMethod, string status) 
    : PaymentId(Ids++), AccountId(accountId), Amount(amount), PaymentMethod(paymentMethod), Status(status) {}
    
   Payment(const Payment& other)
    : PaymentId(other.PaymentId), AccountId(other.AccountId),
      Amount(other.Amount), PaymentMethod(other.PaymentMethod),
      Status(other.Status), Timestamp(other.Timestamp) {}

    int GetPaymentId() {return PaymentId;}
    string GetStatus() {return Status; }
    double GetAmount() {return Amount; }
    void SetAmount(double amount) { Amount = amount; }
    void SetStatus(const string &status) { Status = status; }

    void Display()
    {
        if (PaymentId == -1) return;
        cout  << "Payment: \n"
            << "PaymentId: " << PaymentId << '\n'
            << "AccountId: " << AccountId << "\n"
            << "Amount: " << Amount << "\n"
            << "PaymentMethod : " << PaymentMethodToString(PaymentMethod) << "\n"
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

class CashPayment : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "[Cash] Processing payment of $" << amount << " through cash\n";
    }

    string getMethodName() const override {
        return "cash";
    }
    int getMethodId() const override {
        return 1;
    }
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
        return 2;
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
        return 3;
    }
};