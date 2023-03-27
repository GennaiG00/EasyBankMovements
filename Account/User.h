//
// Created by utente on 18/01/2023.
//

#ifndef BANK_USER_H
#define BANK_USER_H

#include <string>
#include <memory>
#include <map>
#include "Account.h"

class User{
private:
    std::string name;
    std::string surname;
    std::map<std::string, std::unique_ptr<Account>> account;
public:
    User(const std::string& name,const std::string& surname){
        this->name = name;
        this->surname = surname;
    };

    void setAccount(Account *account);

    void addFounds(float money, const std::string& accountName);

    void makeATransfer(float money, const std::string &iban, const std::string& accountName);

    void withdrawMoney(float money, const std::string& accountName);

    const std::string& getIbanFromAccount(const std::string& accountName);

    const std::string& getAmountFromAccount( const std::string& accountName);

    const std::string &getName() const;

    const std::string &getSurname() const;

    std::vector<std::string> getAllMovements(const std::string& accountName = "");

    std::vector<std::string> getMovementsInDate(char* date, const std::string& accountName = "");

    std::vector<std::string> getAccountsName();

};

#endif //BANK_USER_H