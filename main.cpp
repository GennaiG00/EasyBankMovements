#include <iostream>
#include "Account/User.h"
#include "Account/AccountManager.h"

int main() {
    AccountManager accountManager;
    auto user1 = new User("Gian_Maria", "Gennai");
    auto user2 = new User("Gian_Maria", "Gennai");
    accountManager.createNewAccount(user1);
    accountManager.createNewAccount(user2);
    return 0;
}
