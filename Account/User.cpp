//
// Created by utente on 18/01/2023.
//

#include "User.h"

void User::addMoneyToPersonalAccount(float money, bool movement) {
    account->makeMovement(money, movement);
}

void User::withdrawMoneyToPersonalAccount(float money) {

}
