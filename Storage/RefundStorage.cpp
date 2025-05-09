#include <iostream>
#include <vector>
#include "../Models/Refund.cpp"

using namespace std;

class RefundStorage
{
private:
    vector<Refund> refunds;

public:
    void InsertRefund(const Refund &refund)
    {
        refunds.push_back(refund);
    }

    bool DeleteRefund(int refundId)
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

    Refund* GetRefundById(int refundId)
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

    void DisplayAllRefunds()
    {
        for (const auto &refund : refunds)
        {
            refund.Display();
        }
    }
};
