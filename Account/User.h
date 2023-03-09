//
// Created by utente on 18/01/2023.
//

#ifndef BANK_USER_H
#define BANK_USER_H

#include <string>
#include "Account.h"

class User{
private:
    std::string name;
    std::string surname;
    Account* account;
public:
    User(const std::string& name,const std::string& surname){
        this->name = name;
        this->surname = surname;
    };

    void setAccount(Account *account);

    void addFounds(float money);

    void makeATransfer(float money,const std::string &iban);

    void withdrawMoney(float money);

    const std::string& getIbanFromAccount();

    const std::string& getAmountFromAccount();

    const std::string &getName() const;

    const std::string &getSurname() const;
};


#endif //BANK_USER_H