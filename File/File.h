//
// Created by utente on 19/01/2023.
//

#ifndef BANK_FILE_H
#define BANK_FILE_H

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

class File {
private:
    const char* path = "../Data/";
    char* fileString = new char();
    char* combine = new char();

public:
    File() = default;

    std::FILE* openFile(const std::string &fileName);

    void closeFile(std::FILE* file);

    ~File() {
        delete combine;
        delete fileString;
    }

protected:
    std::vector<std::string> getRowFile(std::FILE* file);

    char *read(std::FILE* file);

    void updateFile(const std::string &update, const std::string &name, std::FILE* file);
};


#endif //BANK_FILE_H
