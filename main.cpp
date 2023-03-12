#include <iostream>
#include "Account/User.h"
#include "Account/AccountManager.h"

int main() {
    AccountManager accountmanager;
    auto user = new User("marco", "rossi");
    accountmanager.createNewAccount(user);
    user->addFounds(100);
    return 0;
}
