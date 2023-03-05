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

    bool checkIban(const std::string &iban);

    void addIban(const std::string &iban);

    std::vector<std::string> returnAllIban();

private:
    static IbanFile* instance;
    std::string ibanFileName = "IbanFile";
};

IbanFile* IbanFile::instance = nullptr;

#endif //BANK_IBANFILE_H
