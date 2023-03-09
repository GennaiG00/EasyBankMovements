//
//Created by utente on 05/03/2023.
//

#include <ctime>
#include "AccountManager.h"
#include "../Utility.h"

Account* AccountManager::createNewAccount(User* user) {
    auto iban = new char[27];
    std::string s;
    do {
        iban[27] = '\0';
        iban = createIban(iban);
        s = iban;
    }while(accounts.count(iban) != 0);
    ibanFile.addIban(iban);
    auto clientFile = new ClientFile(s);
    clientFile->safeInformation(user->getName());
    clientFile->safeInformation(user->getSurname());
    clientFile->safeInformation(iban);
    clientFile->safeInformation("0");
    Movements::getInstance()->addIban(s);
    accounts.insert(std::pair<std::string, Account*>(iban, new Account(user->getName(), user->getSurname(), s, 0, clientFile)));
    user->setAccount(accounts.find(iban)->second);
    delete[] iban;
    return accounts.find(s)->second;
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