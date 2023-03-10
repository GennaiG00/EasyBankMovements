//
// Created by genna on 09/03/2022.
//

#include "gtest\gtest.h"
#include "../Account/AccountManager.h"


class BankSuit : public ::testing::Test {
protected:
    AccountManager accountManager;
    User* user = new User("Gian_Maria", "Gennai");
    BankSuit(){
        accountManager.createNewAccount(user);
    }
};

TEST_F(BankSuit, safeAccountData) {
    File file;
    std::vector<std::string> data = file.getRowFile(file.openFile(user->getIbanFromAccount()));
    EXPECT_EQ(data[0],"Gian_Maria");
    EXPECT_EQ(data[1],"Gennai");
    EXPECT_EQ(data[2],user->getIbanFromAccount());
}

TEST_F(BankSuit, addSubMoneyToMyAccount) {
    user->addFounds(100);
    EXPECT_EQ(user->getAmountFromAccount(),"100");
    user->withdrawMoney(50);
    EXPECT_EQ(user->getAmountFromAccount(),"50");
}

TEST_F(BankSuit, makeTransfer) {
    auto userB = new User("Marco", "Polo");
    user->makeATransfer(50, userB->getIbanFromAccount());
    EXPECT_EQ(user->getAmountFromAccount(),"0");
    EXPECT_EQ(userB->getAmountFromAccount(), "50");
}

TEST_F(BankSuit, checkAmountOnFile){
    File file;
    std::vector<std::string> data = file.getRowFile(file.openFile(user->getIbanFromAccount()));
    EXPECT_EQ(data[data.size()-2], user->getAmountFromAccount());
}