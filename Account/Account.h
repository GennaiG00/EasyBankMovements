//
// Created by utente on 18/01/2023.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <ctime>
#include <list>
#include "../File/ClientFile.h"
#include "Movements.h"

class Account{
private:
    std::string userName;
    std::string userSurname;
    std::string iban;
    std::string accountName;
    float amount;
    ClientFile* clientFile;

public:
    Account(const std::string &name,const std::string &surname, std::string &iban, float amount, ClientFile* clientFile,const std::string& accountName) {
        userName = name;
        userSurname = surname;
        this->amount = amount;
        this->iban = iban;
        this->clientFile = clientFile;
        this->accountName = accountName;
    }

    virtual ~Account() = default;

    void addMoney(float money);

    void subMoney(float money);

    const std::string& getAmount();

    const std::string& getIban();

    std::vector<std::string> returnMovements(char* date);

    const std::string &getAccountName() const;

};
#endif //BANK_ACCOUNT_H
