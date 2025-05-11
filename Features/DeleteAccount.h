#pragma once
#include "../Storage/AccountStorage.h"

struct DeleteAccountRequest {
    int accountId;
    DeleteAccountRequest(int id) : accountId(id) {}
};

struct DeleteAccountResponse {
    bool success;
    string message;
    Account deletedAccount;

    DeleteAccountResponse(bool s, const string& m, const Account& acc)
        : success(s), message(m), deletedAccount(acc) {}
};

class DeleteAccountHandler {
private:
    AccountStorage& storage;

public:
    explicit DeleteAccountHandler(AccountStorage& s) : storage(s) {}

    DeleteAccountResponse Handle(const DeleteAccountRequest& request) {
        Account* account = storage.GetAccountById(request.accountId);
        if (account && storage.DeleteAccountById(request.accountId)) {
            return {true, "Account moved to deleted records.", *account};
        }
        return {false, "Account not found.", Account()};
    }
};