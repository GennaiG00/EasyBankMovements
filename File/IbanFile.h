//
// Created by utente on 30/01/2023.
//

#ifndef BANK_IBANFILE_H
#define BANK_IBANFILE_H

#include "File.h"
#include <stdexcept>

class IbanFile : public File{
public:
    bool checkIban(const std::string &iban, const std::string &path);
};


#endif //BANK_IBANFILE_H
