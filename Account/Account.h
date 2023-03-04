//
// Created by utente on 18/01/2023.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <ctime>
#include <list>
#include "../File/MovementsClientFile.h"
#include "../Observer.h"

//TODO: creare un account manager che con l'observer aggiorna la lista di iban

class Account : public Observer{
private:
    std::string userName;
    std::string userSurname;
    std::string iban;
    float amount;
    MovementsClientFile accountFile;

public:
    Account(std::string name, std::string surname) {
        userName = name;
        userSurname = surname;
        iban = new char[27];
        iban[27] = '\0';
        iban = createIban();
    }

    std::string createIban();

    void makeMovement(float money, bool typeOfMovement, std::string iban = "");
};

#endif //BANK_ACCOUNT_H
