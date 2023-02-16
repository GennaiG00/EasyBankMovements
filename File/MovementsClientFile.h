//
// Created by utente on 31/01/2023.
//

#ifndef BANK_MOVEMENTSCLIENTFILE_H
#define BANK_MOVEMENTSCLIENTFILE_H


#include "File.h"

class MovementsClientFile : public File{
public:
    void addMovements(const std::string &money, const std::string &iban);

    std::string& getAmount(const std::string &iban);
};


#endif //BANK_MOVEMENTSCLIENTFILE_H
