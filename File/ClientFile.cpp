//
// Created by utente on 31/01/2023.
//

#include <string>
#include <sstream>
#include "ClientFile.h"
#include "../Utility.h"

void ClientFile::addMovements(const std::string &movements, float money, bool add) {
    std::FILE* file;
    file = openFile(iban);
    float amount = std::stof(getAmount());
    std::string movementStringValue;
    std::stringstream s;
    if(add){
        s << movements;
        movementStringValue = s.str();
        amount += money;
    }else{
        s << movements;
        movementStringValue = s.str();
        amount -= money;
    }
    safeInformation(movementStringValue);
    std::stringstream ss;
    ss << amount;
    safeInformation(ss.str());
    closeFile(file);
}

std::string ClientFile::getAmount() {
    std::FILE* file;
    file = openFile(iban);
    std::vector <std::string> tmpVector = getRowFile(file);
    closeFile(file);
    std::string amount = tmpVector[tmpVector.size()-2];
    return amount;
}

std::vector<std::string> ClientFile::getData() {
    std::FILE* file;
    file = openFile(iban);
    std::vector<std::string> fileRow = getRowFile(file);
    for(int i=0; i < 4; i++)
        fileRow.push_back(getRowFile(file)[i]);
    closeFile(file);
    return fileRow;
}

void ClientFile::safeInformation(const std::string &info) {
    std::FILE* file;
    file = openFile(iban);
    updateFile(info, iban, file);
    closeFile(file);
}

std::vector<std::string> ClientFile::getMovements(char* cDate) {
    std::FILE* file;
    file = openFile(iban);
    std::vector<std::string> fileRow = getRowFile(file);
    std::vector<std::string> data;
    for (int i = 5; i < fileRow.size() - 2; i = i + 2) {
        data.push_back(fileRow[i]);
    }
    if(cDate){
        std::string date(cDate);
        std::vector<std::string> checkDate;
        for(int i=0; i<data.size()-1; i++){
            std::vector<std::string> tmp = split(data[i], ' ');
            checkDate.emplace_back(tmp[3] + " " + tmp[4] + " " + tmp[5] + " " + tmp[7]);
        }
    }
    closeFile(file);
    return data;
}