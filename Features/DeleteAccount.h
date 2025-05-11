#pragma once
#include "../Storage/IRepository.h"

struct DeleteAccountRequest {
    int accountId;
    DeleteAccountRequest(int id) : accountId(id) {}
};

struct DeleteAccountResponse {
    bool success;
    string message;

    DeleteAccountResponse(bool status, const string& msg)
        : success(status), message(msg) {}
};

class DeleteAccountHandler {
private:
    IRepository<Account>& accountRepository;

public:
    explicit DeleteAccountHandler(IRepository<Account>& _repo) : accountRepository(_repo) {}

    DeleteAccountResponse Handle(const DeleteAccountRequest& request) {
        bool deleted = accountRepository.Delete(request.accountId);

        if (deleted)
        {
            return {true, "Account deleted successfully."};
        }
        else
        {
            return {false, "Account not found."};
        }
    }
};