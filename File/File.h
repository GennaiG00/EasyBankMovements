//
// Created by utente on 19/01/2023.
//

#ifndef BANK_FILE_H
#define BANK_FILE_H


#include <cstdio>
#include <string>
#include <vector>

class File {
private:
    std::FILE *file;
    std::string path = "../Bank/Data/";
    char *fileString = new char();
    char *combine = new char();

public:
    File() = default;

    std::FILE* openFile(const std::string &fileName);

    void closeFile();

    ~File() {
        delete combine;
        delete fileString;
    }

protected:
    std::vector<std::string> getRowFile(const std::string &name);

    char *read(const std::string &name);

    void updateFile(const std::string &update, const std::string &name);
};


#endif //BANK_FILE_H
