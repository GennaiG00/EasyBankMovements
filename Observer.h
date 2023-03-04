//
// Created by utente on 25/02/2023.
//

#ifndef BANK_OBSERVER_H
#define BANK_OBSERVER_H

class Observer{
public:
    virtual ~Observer(){}

    virtual void update() = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};

#endif //BANK_OBSERVER_H
