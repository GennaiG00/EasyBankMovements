//
// Created by utente on 18/01/2023.
//

#include "Account.h"
#include "../Utility.h"
#include <sstream>
#include <ctime>


const std::string& Account::getAmount() {
    return clientFile->getAmount();
}

const std::string& Account::getIban() {
    return iban;
}

void Account::addMoney(float money) {
    time_t curr_time;
    curr_time = time(NULL);
    auto tm = ctime(&curr_time);
    std::string sDate = tm;
    sDate.pop_back();
    amount += money;
    std::stringstream s;
    s << amount;
    std::string sMovement = "Add " + s.str() + " in " + sDate;
    clientFile->addMovements(sMovement, money, true);
}

void Account::subMoney(float money) {
    time_t curr_time;
    curr_time = time(NULL);
    auto tm = ctime(&curr_time);
    std::string sDate = tm;
    sDate.pop_back();
    amount -= money;
    std::stringstream s;
    s << amount;
    std::string sMovement = "Withdraw " + s.str() + " in " + sDate;
    clientFile->addMovements(sMovement, money , false);
}

std::vector<std::string> Account::returnMovements(char* date) {
    return clientFile->getMovements(date);
}

const std::string &Account::getAccountName() const {
    return accountName;
}
