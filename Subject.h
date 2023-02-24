//
// Created by utente on 24/02/2023.
//

#ifndef BANK_SUBJECT_H
#define BANK_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;
};

#endif //BANK_SUBJECT_H
