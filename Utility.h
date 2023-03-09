//
// Created by utente on 18/01/2023.
//

#include <vector>
#include <string>

#ifndef BANK_UTILITY_H
#define BANK_UTILITY_H

inline std::vector<std::string> split(std::string &data, const char demilimiter, int elem = 1) {
    size_t pos = 0;
    std::vector<std::string> splitArray;

    int count = 0;
    while ((pos = data.find(demilimiter)) != std::string::npos && ((elem == 1) || (count < elem - 1))) {
        splitArray.push_back(data.substr(0, pos));
        data.erase(0, pos + 1);
        count++;
    }

    splitArray.push_back(data);

    return splitArray;
}

inline char generateRandomNumber(){
    const char randomNumber[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    return randomNumber[rand() % (sizeof(randomNumber) - 1)];;
}

inline char generateRandomLetter(){
    const char randomLetter[5] = {'A', 'B', 'C', 'D', 'E'};
    return randomLetter[rand() % (sizeof(randomLetter) - 1)];
}

#endif //BANK_UTILITY_H