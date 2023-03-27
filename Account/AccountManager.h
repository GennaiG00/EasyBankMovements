//
// Created by utente on 05/03/2023.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H

#include <map>
#include <vector>
#include "../File/IbanFile.h"
#include "../File/ClientFile.h"
#include "Movements.h"
#include "Account.h"
#include "User.h"


#include <map>
#include <vector>
#include "../File/IbanFile.h"
#include "../File/ClientFile.h"
#include "Movements.h"
#include "Account.h"
#include "User.h"

class AccountManager{
private:
    IbanFile ibanFile;
    std::map<std::string, Account*> accounts;
    char* createIban(char* iban);

public:
    AccountManager(){
        std::vector<std::string> allIban = ibanFile.returnAllIban();
        for(int i=0; i<allIban.size()-1; i++){
            auto clientFile = new ClientFile(allIban[i]);
            std::vector<std::string> data = clientFile->getData();
            Movements::getInstance()->addIban(data[2]);
            auto a = new Account(data[0], data[1], data[2], std::stof(data[data.size()-2]), clientFile,  data[3]);
            accounts.insert(std::pair<std::string, Account*>(data[2], a));
        }
    }

    Account* createNewAccount(User* user,const std::string& accountName);

    ~AccountManager() = default;
};

#endif //BANK_ACCOUNTMANAGER_H