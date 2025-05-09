#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    int AccountId;
    string HandlerName;

public:
    Account() = default;
    Account(int id, const string& name) : AccountId(id), HandlerName(name) {}

    int getAccountId() const { return AccountId; }
    string getHandlerName() const { return HandlerName; }

    void setAccountId(int id) { AccountId = id; }
    void setHandlerName(const string& name) { HandlerName = name; }

    void printAccount() const {
        cout << "Account ID: " << AccountId << "\n";
        cout << "Handler Name: " << HandlerName << "\n";
    }
};