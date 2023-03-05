//
// Created by utente on 31/01/2023.
//

#ifndef BANK_MOVEMENTSCLIENTFILE_H
#define BANK_MOVEMENTSCLIENTFILE_H


#include "File.h"

class MovementsClientFile : public File{
private:
    std::string iban;
public:
    MovementsClientFile(std::string &iban){
        this->iban = iban;
        openFile(iban);
    }

    void addMovements(const std::string &money, const std::string &iban);

    std::string& getAmount(const std::string &iban);

    std::vector<std::string> getData();

};


#endif //BANK_MOVEMENTSCLIENTFILE_H
