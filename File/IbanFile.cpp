//
// Created by utente on 30/01/2023.
//

#include "IbanFile.h"

bool IbanFile::checkIban(const std::string &iban) {
        std::vector <std::string> tmpVector = getRowFile("iban");
        for (int i = 0; i < tmpVector.size(); i++) {
            if (iban == tmpVector[i]) {
                return true;
            }
        }
        throw std::runtime_error("Iban non trovato");
}



void IbanFile::addIban(const std::string &iban) {
    updateFile(iban, "iban");
}

IbanFile *IbanFile::getInstance() {
    if(instance == nullptr)
        instance = new IbanFile();
    return instance;
}

std::vector<std::string> IbanFile::returnAllIban() {
    return getRowFile(ibanFileName);
}
