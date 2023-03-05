//
// Created by utente on 31/01/2023.
//

#include <string>
#include "MovementsClientFile.h"

void MovementsClientFile::addMovements(const std::string &money, const std::string &iban) {
    updateFile(money, iban);
}

std::string &MovementsClientFile::getAmount(const std::string &iban) {
    std::vector <std::string> tmpVector = getRowFile(iban);
    std::string tmpString = tmpVector[tmpVector.size()-2];
    return tmpString;
}

std::vector<std::string> MovementsClientFile::getData() {
    return getRowFile(iban);
}
