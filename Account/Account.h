//
// Created by utente on 18/01/2023.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <ctime>

class Account {
private:
    std::string userName;
    std::string userSurname;
    std::string iban;
    float amount;
    Movements movement;

public:
    Account(std::string name, std::string surname) {
        userName = name;
        userSurname = surname;
        iban = new char[27];
        iban[27] = '\0';
        iban = createIban();
    }

    std::string createIban();
};

#endif //BANK_ACCOUNT_H
