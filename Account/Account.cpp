//
// Created by utente on 18/01/2023.
//

#include "Account.h"
#include "../Utility.h"
#include <sstream>

const std::string& Account::getAmount() {
    return clientFile->getAmount();
}

const std::string& Account::getIban() {
    return iban;
}

void Account::addMoney(float money) {
    amount += money;
    std::stringstream s;
    s << amount;
    std::string sAmount = s.str();
    clientFile->addMovements(sAmount, true);
}

void Account::subMoney(float money) {
    amount -= money;
    std::stringstream s;
    s << amount;
    std::string sAmount = s.str();
    clientFile->addMovements(sAmount, false);
}

void Account::setMovements(Transactions *movements) {
    Account::movements = movements;
}

