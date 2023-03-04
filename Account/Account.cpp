//
// Created by utente on 18/01/2023.
//

#include <sstream>
#include "Account.h"
#include "../Utility.h"

std::string Account::createIban() {
    iban[0] = 'I';
    iban[1] = 'T';
    srand(time(NULL));
    for (int i = 2; i < 4; i++) {
        iban[i] = generateRandomNumber();
    }
    iban[4] = generateRandomLetter();
    for (int i = 5; i < 10; i++) {
        iban[i] = generateRandomNumber();
    }
    for (int i = 10; i < 15; i++) {
        iban[i] = generateRandomNumber();
    }
    for (int i = 15; i < 27; i++) {
        iban[i] = generateRandomNumber();
    }
    return iban;
}

void Account::makeMovement(float money, bool typeOfMovement, std::string iban) {
    std::stringstream stream;
    if(iban.empty()){
        if(typeOfMovement) {
            stream << movement->addMoneyToPersonalAccount(money);
            accountFile.addMovements(stream.str(), this->iban);
        }
        else{
            stream << movement->subMoneyToPersonalAccount(money);
            accountFile.addMovements(stream.str(), this->iban);
        }
    }else{
        if(typeOfMovement) {
            stream << movement->makeMovementFromAnotherAccount(money, iban);
            accountFile.addMovements(stream.str(), )
        }
    }
}

