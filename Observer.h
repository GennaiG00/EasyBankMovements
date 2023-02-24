//
// Created by utente on 24/02/2023.
//

#ifndef BANK_OBSERVER_H
#define BANK_OBSERVER_H

#include <string>

class Observer{
public:
    virtual ~Observer() {}

    virtual void update(float x, bool movement = true, std::string iban = "") = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};

#endif //BANK_OBSERVER_H
