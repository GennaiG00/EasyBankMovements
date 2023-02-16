//
// Created by utente on 30/01/2023.
//

#ifndef BANK_IBANFILE_H
#define BANK_IBANFILE_H

#include "File.h"
#include <stdexcept>

class IbanFile : public File{
public:
    static IbanFile* getInstance();

    bool checkIban(const std::string &iban, const std::string &path);

    void addIban(const std::string &iban);
private:
    static IbanFile* instance;
};

IbanFile* IbanFile::instance = nullptr;

#endif //BANK_IBANFILE_H
