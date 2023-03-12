//
// Created by utente on 31/01/2023.
//

#include <string>
#include <sstream>
#include "ClientFile.h"

void ClientFile::addMovements(const std::string &money, bool add) {
    std::FILE* file;
    file = openFile(iban);
    float movementMoney = std::stof(money);
    float amount = std::stof(getAmount());
    std::string movementStringValue;
    std::stringstream s;
    if(add){
        s << "+" << money;
        movementStringValue = s.str();
        amount += movementMoney;
    }else{
        s << "-" << money;
        movementStringValue = s.str();
        amount -= movementMoney;
    }
    safeInformation(movementStringValue);
    s.str("");
    s << amount;
    std::cout << s.str();
    safeInformation(s.str());
    closeFile(file);
}

const std::string& ClientFile::getAmount() {
    std::FILE* file;
    file = openFile(iban);
    std::vector <std::string> tmpVector = getRowFile(file);
    closeFile(file);
    return tmpVector[tmpVector.size()-2];
}

std::vector<std::string> ClientFile::getData() {
    std::FILE* file;
    file = openFile(iban);
    std::vector<std::string> fileRow = getRowFile(file);
    closeFile(file);
    return fileRow;
}

void ClientFile::safeInformation(const std::string &info) {
    std::FILE* file;
    file = openFile(iban);
    updateFile(info, iban, file);
    closeFile(file);
}
