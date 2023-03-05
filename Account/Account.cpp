//
// Created by utente on 18/01/2023.
//

#include <sstream>
#include "Account.h"
#include "../Utility.h"

//void Account::makeMovement(float money, bool typeOfMovement, std::string iban) {
//    std::stringstream stream;
//    if(iban.empty()){
//        if(typeOfMovement) {
//            stream << movement->addMoneyToPersonalAccount(money);
//            accountFile.addMovements(stream.str(), this->iban);
//        }
//        else{
//            stream << movement->subMoneyToPersonalAccount(money);
//            accountFile.addMovements(stream.str(), this->iban);
//        }
//    }else{
//        if(typeOfMovement) {
//            stream << movement->makeMovementFromAnotherAccount(money, iban);
//            accountFile.addMovements(stream.str(), )
//        }
//    }
//}

//void Account::update(float money, bool addMoney) {
//    if(addMoney)
//        amount += money;
//    else
//        amount -= money;
//    accountFile.addMovements(std::to_string(amount), iban);
//}

float Account::getAmount() {
    amount = std::stof(accountFile->getAmount(this->iban));
    accountFilecloseFile();
    return 0;
}

const std::string &Account::getIban() const {
    return iban;
}

