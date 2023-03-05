//
// Created by utente on 05/03/2023.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H


#include "../File/IbanFile.h"
#include "../File/MovementsClientFile.h"
#include "Account.h"

class AccountManager {
private:
    IbanFile ibanFile;
    std::vector<std::string> allIban;
    std::vector<Account*> accounts;
public:
    AccountManager(){
        allIban = ibanFile.returnAllIban();
        for(int i=0; i<allIban.size(); i++){
            auto clientFile = new MovementsClientFile(allIban[i]);
            std::vector<std::string> data = clientFile->getData();
            accounts.push_back(new Account(data[0], data[1], allIban[i], std::stof(data[data.size()-1]), clientFile));
        }
    }

    void createNewAccount(std::string &name, std::string &surname);

    char* createIban(char* iban);
};


#endif //BANK_ACCOUNTMANAGER_H
