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
    MovementsClientFile *accountFile;

public:
    Account(std::string &name, std::string &surname, std::string &iban, float amount, MovementsClientFile* movementsClientFile) {
        userSurname = name;
        userSurname = surname;
        this->amount = amount;
        accountFile = movementsClientFile;
    }

    virtual ~Account(){
        accountFile->closeFile();
    };

    std::string createIban();

    void makeMovement(float money, bool typeOfMovement, std::string iban = "");

    float getAmount();

    const std::string &getIban() const;

    virtual void update(float money, bool addMoney) override;
    virtual void attach() override;
    virtual void detach() override;
};

#endif //BANK_ACCOUNT_H
