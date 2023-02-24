//
// Created by utente on 18/01/2023.
//

#ifndef BANK_USER_H
#define BANK_USER_H


#include <string>
#include "Account.h"

class User {
private:
    std::string name;
    std::string surname;
    Account* account;
public:
    User(std::string& name, std::string& surname){
        this->name = name;
        this->surname = surname;
    };

    void createAccount(){
        account = new Account(name, surname);
    };

    void addMoneyToPersonalAccount(float money, bool movement = true);

    void doBankTransfer(float money, std::string &iban);

    void withdrawMoneyToPersonalAccount(float money);

    std::string& getAmountFromAccount();

};


#endif //BANK_USER_H
