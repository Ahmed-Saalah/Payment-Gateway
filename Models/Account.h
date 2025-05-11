#pragma once

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    int AccountId;
    string HandlerName; 
    string Password;
    static int identity;

public:
    Account(): AccountId(-1) {}

    Account(const string& name , string password)
        : AccountId(identity++), HandlerName(name), Password(password) {}
    
    Account(const Account& other) :
        AccountId(other.AccountId), 
        Password(other.Password),
        HandlerName(other.HandlerName) {}


    int getAccountId() const { return AccountId; }

    string getHandlerName() const { return HandlerName; }

    string getPassword() const{ return Password; }

    void setPassword(string password){ Password = password;}

    void setAccountId(int id) { AccountId = id; }
    
    void setHandlerName(const string& name) { HandlerName = name; }

    void Display() const {
        cout << "Account: \n"
            << "AccountId: " << AccountId << "\n"
            << "Handler Name: " << HandlerName << "\n" << endl;
    }
};

int Account::identity =1;