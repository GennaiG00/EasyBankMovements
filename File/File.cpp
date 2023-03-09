//
// Created by utente on 19/01/2023.
//

#include "File.h"
#include "../Utility.h"

std::vector <std::string> File::getRowFile(std::FILE* file) {
    std::vector <std::string> tmpVector;
    char *stempChar = this->read( file);
    std::string str(stempChar);
    tmpVector = split(str, '\n');
    delete stempChar;
    return tmpVector;
}

std::FILE* File::openFile(const std::string &fileName) {
    std::string txt = ".txt";
    std::string chain = this->path + fileName + txt;
    const char *tmp_chain = chain.c_str();
    return fopen(tmp_chain, "a+");
}

void File::closeFile(std::FILE* file) {
    fclose(file);
}

void File::updateFile(const std::string &update, const std::string &name, std::FILE* file) {
    fprintf(file, "%s\n", update.c_str());
}

char *File::read(std::FILE* file) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    char *str = new char[size + 1];
    fread(str, sizeof(char), size, file);

    str[size] = '\0';

    return str;
}