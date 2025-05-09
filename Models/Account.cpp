#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    int AccountId;
    string HandlerName; 
    string Password;
    static int Ids;

public:
    Account() = default;
    Account(const string& name , string password): AccountId(Ids++), HandlerName(name), Password(password) {}

    int getAccountId() const { return AccountId; }
    string getHandlerName() const { return HandlerName; }
    string getPassword()const{ return password;}

    void setPassword(string password){ Password = password;}
    void setAccountId(int id) { AccountId = id; }
    void setHandlerName(const string& name) { HandlerName = name; }

    void printAccount() const {
        cout << "Account ID: " << AccountId << "\n";
        cout << "Handler Name: " << HandlerName << "\n";
    }
};
    int Account::Ids;