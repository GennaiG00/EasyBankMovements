//
// Created by utente on 30/01/2023.
//

#ifndef BANK_TRANSACTIONS_H
#define BANK_TRANSACTIONS_H

#include <string>
#include <vector>

class Transactions{
private:
    std::vector<std::string> iban;
    Transactions() = default;
    static Transactions* instance;

public:
    void makeMovementFromAnotherAccount(float money, const std::string &toIban, const std::string &fromIban);

    void addIban(const std::string& newIban);

    static Transactions* getInstance();
};

#endif //BANK_TRANSACTIONS_H

