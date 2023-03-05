//
// Created by utente on 19/01/2023.
//

#include "File.h"
#include "../Utility.h"

std::vector <std::string> File::getRowFile(const std::string &name) {
    std::vector <std::string> tmpVector;
    char *stempChar = this->read(name);
    std::string str(stempChar);
    tmpVector = split(str, '\n');
    delete stempChar;
    return tmpVector;
}

std::FILE* File::openFile(const std::string &fileName) {
    std::FILE *file;
    std::string txt = ".txt";
    std::string chain = this->path + fileName + txt;
    const char *tmp_chain = chain.c_str();
    return fopen(tmp_chain, "a+");
}

void File::closeFile() {
    fclose(file);
}

void File::updateFile(const std::string &update, const std::string &name) {
    openFile(name);
    fprintf(file, "%s\n", update.c_str());
    closeFile();
}

char *File::read(const std::string &name) {
    openFile(name);
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    char *str = new char[size + 1];
    fread(str, sizeof(char), size, file);

    str[size] = '\0';

    closeFile();
    return str;
}