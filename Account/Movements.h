//
// Created by utente on 30/01/2023.
//

#ifndef BANK_MOVEMENTS_H
#define BANK_MOVEMENTS_H

#include "../File/MovementsClientFile.h"
#include "../Observer.h"

class Movements : public Observer {
private:
    float balancingItem = 0;

public:
    Movements(float balancingItem){
        this->balancingItem = balancingItem;
    }

    void addMoney(const std::string &iban, float money);

    void subMoney(const std::string &iban, float money);

};


#endif //BANK_MOVEMENTS_H
