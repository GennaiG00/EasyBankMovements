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
    std::string chain;
    char *fileString = new char();
    char *combine = new char();

public:
    File() = default;

    std::FILE* openFile(const std::string &fileName, const std::string &path);

    void closeFile();

    ~File() {
        delete combine;
        delete fileString;
    }

protected:
    std::vector<std::string> getRowFile(const std::string &name, const std::string &path);

    char *read(const std::string &name, const std::string &path);

    void updateFile(const std::string &update, const std::string &name, const std::string& path);
};


#endif //BANK_FILE_H
