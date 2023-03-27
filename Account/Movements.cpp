//
// Created by utente on 30/01/2023.
//

#include "Movements.h"
#include "../File/ClientFile.h"
#include <sstream>
#include <iostream>
#include "MovementsException.h"
#include <ctime>

Movements* Movements::instance = nullptr;

void Movements::makeMovementFromAnotherAccount(const float money, const std::string &toIban, const std::string &fromIban) {
    time_t curr_time;
    curr_time = time(NULL);
    auto tm = ctime(&curr_time);
    bool equal = false;
    for(auto ptr = iban.begin(); ptr < iban.end(); ptr++){
        if(*ptr == toIban)
            equal = true;
    }
    if(equal){
        ClientFile clientFileFrom(fromIban);
        ClientFile clientFileTo(toIban);
        std::stringstream s;
        std::string sDate = tm;
        sDate.pop_back();
        s << money;
        std::string sMovementTo = "Add " + s.str() + " in " + sDate + " from " + clientFileFrom.getData()[0] + " " + clientFileFrom.getData()[1];
        std::string sMovementFrom = "Sub " + s.str() + " in " + sDate + " to " + clientFileFrom.getData()[0] + " " + clientFileFrom.getData()[1];
        clientFileFrom.addMovements(sMovementFrom, money , false);
        clientFileTo.addMovements(sMovementTo, money , true);
    }else{
        throw MovementsException(toIban);
    }
}
void Movements::addIban(const std::string& newIban) {
    bool equal = false;
    for(auto ptr = iban.begin(); ptr < iban.end(); ptr++){
        if(*ptr == newIban)
            equal = true;
    }
    if(!equal){
        iban.push_back(newIban);
    }
    for(auto i : iban)
        std::cout << i;
}

Movements* Movements::getInstance() {
    if(instance == nullptr)
        instance = new Movements;
    return instance;
}