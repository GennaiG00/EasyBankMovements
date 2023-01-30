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

    const std::string &getName() const;

    const std::string &getSurname() const;

    void createAccount(){
        account = new Account(name, surname);
    };

};


#endif //BANK_USER_H
