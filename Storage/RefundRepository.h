#pragma once

#include <iostream>
#include <vector>
#include "../Models/Refund.h"
#include "IRepository.h"

using namespace std;

class RefundRepository : public IRepository<Refund>
{
private:
    static vector<Refund> refunds;

public:
    void Insert(const Refund &refund) override
    {
        refunds.push_back(refund);
    }

    bool Delete(int refundId) override
    {
        for (auto it = refunds.begin(); it != refunds.end(); ++it)
        {
            if (it->getRefundId() == refundId)
            {
                refunds.erase(it);
                return true;
            }
        }
        return false;
    }

    Refund* GetById(int refundId) override
    {
        for (auto &refund : refunds)
        {
            if (refund.getRefundId() == refundId)
            {
                return &refund;
            }
        }
        return nullptr;
    }


    bool Update(int id, Refund& updatedItem) override
    {
        for (auto& refund : refunds)
        {
            if (refund.getRefundId() == id)
            {
                refund.setStatus(updatedItem.getStatus());
                return true;
            }
        }
        return false;
    }

    void DisplayAll() const override
    {
        if (refunds.empty())
        {
            cout << "No refund stored.\n";
            return;
        }

        for (const auto& refund : refunds)
        {
            refund.Display();
        }
    }
};

vector<Refund> RefundRepository::refunds;