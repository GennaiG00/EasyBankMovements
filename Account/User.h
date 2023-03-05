//
// Created by utente on 18/01/2023.
//

#ifndef BANK_USER_H
#define BANK_USER_H


#include <string>
#include "../Subject.h"
#include "AccountManager.h"

class User : public Subject{
private:
    std::string name;
    std::string surname;
    Account* account;
    std::list<Observer*> observers;
public:
    User(const std::string& name,const std::string& surname){
        this->name = name;
        this->surname = surname;
    };

    void createAccount(){
        AccountManager accountManager;
        accountManager.createNewAccount(name, surname);
    };

    void addMoneyToPersonalAccount(float money);

    void doBankTransfer(float money, std::string &iban);

    void withdrawMoneyToPersonalAccount(float money);

    std::string& getAmountFromAccount();


    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

};


#endif //BANK_USER_H
