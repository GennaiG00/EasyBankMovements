//
// Created by utente on 30/01/2023.
//

#include "Transactions.h"
#include "../File/ClientFile.h"
#include <sstream>
#include <iostream>
#include "MovementsException.h"

Transactions* Transactions::instance = nullptr;

void Transactions::makeMovementFromAnotherAccount(const float money, const std::string &toIban, const std::string &fromIban) {

    bool equal = false;
    for(auto ptr = iban.begin(); ptr < iban.end(); ptr++){
        if(*ptr == toIban)
            equal = true;
    }
    if(equal){
        ClientFile clientFileFrom(fromIban);
        ClientFile clientFileTo(toIban);
        std::stringstream s;
        s << money;
        clientFileFrom.addMovements(s.str(), false);
        clientFileTo.addMovements(s.str(), true);
    }else{
        throw MovementsException(toIban);
    }
}

void Transactions::addIban(const std::string& newIban) {
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

Transactions* Transactions::getInstance() {
    if(instance == nullptr)
        instance = new Transactions;
    return instance;
}
