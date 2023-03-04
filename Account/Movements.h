//
// Created by utente on 30/01/2023.
//

#ifndef BANK_MOVEMENTS_H
#define BANK_MOVEMENTS_H

#include <string>
#include <list>
#include "../Subject.h"

class Movements : public Subject{
private:
    float balancingItem = 0;
    std::list<Observer*> observers;
public:
    Movements(float balancingItem){
        this->balancingItem = balancingItem;
    }



    float addMoneyToPersonalAccount(float money);

    float subMoneyToPersonalAccount(float money);

    float makeMovementFromAnotherAccount(float money, std::string &iban);

    float getAmount(){
        return balancingItem;
    }

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

};


#endif //BANK_MOVEMENTS_H
