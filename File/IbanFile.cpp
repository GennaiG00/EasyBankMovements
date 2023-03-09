//
// Created by utente on 30/01/2023.
//

#include "IbanFile.h"

bool IbanFile::checkIban(const std::string &iban) {
    std::FILE* file;
    file = openFile(ibanFileName);
    std::vector <std::string> tmpVector = getRowFile(file);
    closeFile(file);
    for (int i = 0; i < tmpVector.size(); i++) {
        if (iban == tmpVector[i]) {
            return true;
        }
    }
    return false;
}



void IbanFile::addIban(const std::string &iban) {
    std::FILE* file;
    file = openFile(ibanFileName);
    updateFile(iban, ibanFileName, file);
    closeFile(file);
}

std::vector<std::string> IbanFile::returnAllIban() {
    std::FILE* file;
    file = openFile(ibanFileName);
    auto rowFile = getRowFile(file);
    closeFile(file);
    return rowFile;
}
