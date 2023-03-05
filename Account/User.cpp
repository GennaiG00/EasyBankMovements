//
// Created by utente on 18/01/2023.
//

#include "User.h"
#include "../File/IbanFile.h"

void User::addMoneyToPersonalAccount(float money) {
    account->update(money, true);
}

void User::withdrawMoneyToPersonalAccount(float money) {
    account->update(money, false);
}

void User::subscribe(Observer *o) {
    observers.push_back(o);
}

void User::unsubscribe(Observer *o) {
    observers.remove(o);
}
//
//void User::notify() {
//    for( auto itr = std::begin(observers); itr != std::end(observers); itr++)
//        (*itr)->update();
//}

//void User::doBankTransfer(float money, std::string &iban, Account account) {
//    IbanFile ibanFile;
//    if(ibanFile.checkIban(iban)){
//        account->update(money, false);
//
//    }
//}
