//
// Created by utente on 30/01/2023.
//

#include "Movements.h"

float Movements::addMoneyToPersonalAccount(float money) {
    balancingItem += money;
    return balancingItem;
//    tmpValue = std::stof(movementsFile.getAmount(iban));
//    tmpValue += money;
//    movementsFile.addMovements(std::to_string(tmpValue),iban);
}

float Movements::subMoneyToPersonalAccount(float money) {
    if(balancingItem>=money){
        balancingItem -= money;
        return balancingItem;
    }else{
        throw ("You have no more MONEY!!!");
    }
//    float tmpValue;
//    tmpValue = std::stof(movementsFile.getAmount(iban));
//    if(tmpValue>=money) {
//        tmpValue -= money;
//        movementsFile.addMovements(std::to_string(tmpValue), iban);
//    }else{
//        throw "You have no more MONEY!!!";
//    }
}

float Movements::makeMovementFromAnotherAccount(float money, std::string &iban) {
    return 0;
}

void Movements::subscribe(Observer *o) {
    observers.push_back(o);
}

void Movements::unsubscribe(Observer *o) {
    observers.remove(o);
}
//
//void Movements::notify() {
//    for(auto itr = std::begin(observers); itr != std::end(observers); itr++){
//        (*itr)->update();
//    }
//}