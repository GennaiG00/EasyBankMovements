//
// Created by utente on 18/01/2023.
//
//
#include "User.h"


void User::addFounds(float money) {
    account->addMoney(money);
}

void User::makeATransfer(float money,const std::string &iban) {
    try {
        Transactions::getInstance()->makeMovementFromAnotherAccount(money, iban, account->getIban());
    }catch(const std::runtime_error &e){
        std::cout << e.what();
    }
}

void User::withdrawMoney(float money) {
    account->subMoney(money);
}

const std::string &User::getIbanFromAccount() {
    return account->getIban();
}

const std::string &User::getAmountFromAccount() {
    return account->getAmount();
}

const std::string &User::getName() const {
    return name;
}

const std::string &User::getSurname() const {
    return surname;
}

void User::setAccount(Account *account) {
    User::account = account;
}
