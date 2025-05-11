#pragma once

#include <iostream> 
#include <vector>
#include "../Models/Payment.h"
#include "IRepository.h"

using namespace std; 

class PaymentRepository : public IRepository<Payment>
{
private:
    static vector<Payment> payments;

public:
    void Insert(const Payment &payment) override
    {
        payments.push_back(payment);
    }

    Payment* GetById(int paymentId) override
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

    bool Update(int id, Payment& updatedItem) override
    {
        for (auto& payment : payments)
        {
            if (payment.GetPaymentId() == id)
            {
                payment.SetAmount(updatedItem.GetAmount());
                payment.SetStatus(updatedItem.GetStatus());
                return true;
            }
        }
        return false;
    }

    bool Delete(int id) override
    {
        for (auto it = payments.begin(); it != payments.end(); ++it)
        {
            if (it->GetPaymentId() == id)
            {
                payments.erase(it);
                return true;
            }
        }
        return false;
    }
    
    void DisplayAll() const override
    {
        if (payments.empty())
        {
            std::cout << "No payments stored.\n";
            return;
        }

        for (const auto& payment : payments)
        {
            payment.Display();
        }
    }

    // void SeedData()
    // {
    //     payments.push_back(Payment(1, 100.0, "paid"));
    //     payments.push_back(Payment(2, 200.5, "created"));
    //     payments.push_back(Payment(3, 300.25, "paid"));
    // }
};

vector<Payment> PaymentRepository::payments;