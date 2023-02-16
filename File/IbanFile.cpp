//
// Created by utente on 30/01/2023.
//

#include "IbanFile.h"

bool IbanFile::checkIban(const std::string &iban, const std::string &path) {
        std::vector <std::string> tmpVector = getRowFile("iban", path);
        for (int i = 0; i < tmpVector.size(); i++) {
            if (iban == tmpVector[i]) {
                return true;
            }
        }
        throw std::runtime_error("Iban non trovato");
}



void IbanFile::addIban(const std::string &iban) {
    updateFile(iban, "iban", "./Data/");
}

IbanFile *IbanFile::getInstance() {
    if(instance == nullptr)
        instance = new IbanFile();
    return instance;
}
