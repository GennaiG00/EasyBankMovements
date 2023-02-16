//
// Created by utente on 30/01/2023.
//

#ifndef BANK_MOVEMENTS_H
#define BANK_MOVEMENTS_H

#include "../File/MovementsClientFile.h"

class Movements {
private:
    MovementsClientFile movementsFile;

public:
    void addMoney(const std::string &iban, float money);

    void subMoney(const std::string &iban, float money);

};


#endif //BANK_MOVEMENTS_H
