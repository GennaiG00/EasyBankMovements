//
// Created by utente on 31/01/2023.
//

#ifndef BANK_CLIENTFILE_H
#define BANK_CLIENTFILE_H

#include "File.h"

class ClientFile : public File{
private:
    std::string iban;
public:
    ClientFile(const std::string &iban){
        this->iban = iban;
        closeFile(openFile(iban));
    }

    void safeInformation(const std::string &info);

    void addMovements(const std::string &movements, float money , bool add);

    std::string getAmount();

    std::vector<std::string> getData();

    std::vector<std::string> getMovements(char* cDate = nullptr);

};


#endif //BANK_CLIENTFILE_H
