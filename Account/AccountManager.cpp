//
//Created by utente on 05/03/2023.
//

#include "AccountManager.h"
#include "../Utility.h"

void AccountManager::createNewAccount(std::string &name, std::string &surname) {
        auto iban = new char[27];
        iban[27] = '\0';
        iban = createIban(iban);
        auto clientFile = new MovementsClientFile((std::string&)iban);
        accounts.push_back(new Account(name, surname, (std::string&)iban, 0, clientFile));
}

char* AccountManager::createIban(char* iban) {
    iban[0] = 'I';
    iban[1] = 'T';
    srand(time(NULL));
    for (int i = 2; i < 4; i++) {
        iban[i] = generateRandomNumber();
    }
    iban[4] = generateRandomLetter();
    for (int i = 5; i < 10; i++) {
        iban[i] = generateRandomNumber();
    }
    for (int i = 10; i < 15; i++) {
        iban[i] = generateRandomNumber();
    }
    for (int i = 15; i < 27; i++) {
        iban[i] = generateRandomNumber();
    }
    return iban;
}