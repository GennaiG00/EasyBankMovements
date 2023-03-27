//
// Created by utente on 18/01/2023.
//
//
#include "User.h"


void User::addFounds(float money ,const std::string& accountName) {
    (account.find(accountName)->second)->addMoney(money);
}

void User::makeATransfer(float money,const std::string &iban ,const std::string& accountName) {
    try {
        Movements::getInstance()->makeMovementFromAnotherAccount(money, iban, account.find(accountName)->second->getIban());
    }catch(const std::runtime_error &e){
        std::cout << e.what();
    }
}

void User::withdrawMoney(float money ,const std::string& accountName) {
    (account.find(accountName)->second)->subMoney(money);
}

const std::string &User::getIbanFromAccount(const std::string& accountName) {
    return account.find(accountName)->second->getIban();
}

const std::string &User::getAmountFromAccount(const std::string& accountName) {
    return account.find(accountName)->second->getAmount();
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getSurname() const {
    return surname;
}

void User::setAccount(Account *account) {
    User::account.insert(std::pair<std::string, Account* >(account->getAccountName(), account));
}

std::vector<std::string> User::getAllMovements(const std::string& accountName) {
    if(account.find(accountName)->second)
        return account.find(accountName)->second->returnMovements(nullptr);
    else
        throw std::invalid_argument("Account don't exists!!");
}

std::vector<std::string> User::getMovementsInDate(char* date, const std::string& accountName) {
    if(account.find(accountName)->second)
        return account.find(accountName)->second->returnMovements(date);
    else
        throw std::invalid_argument("Account don't exists!!");
}

std::vector<std::string> User::getAccountsName() {
    std::vector<std::string> accountsName;
    for(auto & itr : account){
        accountsName.push_back(itr.first);
    }
    return accountsName;
}