//
// Created by utente on 09/03/2023.
//

#ifndef PROGETTOPROGRAMMAZIONE_MOVEMENTSEXCEPTION_H
#define PROGETTOPROGRAMMAZIONE_MOVEMENTSEXCEPTION_H

#include <exception>

class MovementsException : public std::runtime_error{
public:
    MovementsException(const std::string& iban) : std::runtime_error("Iban: " + iban + " non trovato!"){};
};

#endif //PROGETTOPROGRAMMAZIONE_MOVEMENTSEXCEPTION_H
