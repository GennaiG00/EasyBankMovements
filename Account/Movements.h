//
// Created by utente on 30/01/2023.
//

#ifndef BANK_MOVEMENTS_H
#define BANK_MOVEMENTS_H

#include <string>
#include <vector>

class Movements{
private:
    std::vector<std::string> iban;
    Movements() = default;
    static Movements* instance;

public:
    void makeMovementFromAnotherAccount(float money, const std::string &toIban, const std::string &fromIban);

    void addIban(const std::string& newIban);

    static Movements* getInstance();
};

#endif //BANK_MOVEMENTS_H

