//
// Created by utente on 30/01/2023.
//

#include "Movements.h"

void Movements::addMoney(const std::string &iban, float money) {
    float tmpValue;
    tmpValue = std::stof(movementsFile.getAmount(iban));
    tmpValue += money;
    movementsFile.addMovements(std::to_string(tmpValue),iban);
}

void Movements::subMoney(const std::string &iban, float money) {
    float tmpValue;
    tmpValue = std::stof(movementsFile.getAmount(iban));
    if(tmpValue>=money) {
        tmpValue -= money;
        movementsFile.addMovements(std::to_string(tmpValue), iban);
    }else{
        throw "You have no more MONEY!!!";
    }
}
