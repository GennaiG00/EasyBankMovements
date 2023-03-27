//
// Created by genna on 09/03/2022.
//

#include "gtest\gtest.h"
#include "../Account/AccountManager.h"
#include "../Account/MovementsException.h"


class BankSuit : public ::testing::Test {
protected:
    AccountManager accountManager;
    User* user = new User("Gian_Maria", "Gennai");
    BankSuit(){
        accountManager.createNewAccount(user,"casa");
        accountManager.createNewAccount(user, "lavoro");
    }
};

TEST_F(BankSuit, safeAccountData) {
    File file;
    std::vector<std::string> data = file.getRowFile(file.openFile(user->getIbanFromAccount("lavoro")));
    EXPECT_EQ(data[1],"Gian_Maria");
    EXPECT_EQ(data[2],"Gennai");
    EXPECT_EQ(data[0],user->getIbanFromAccount("lavoro"));
}

TEST_F(BankSuit, addSubMoneyToMyAccount) {
    user->addFounds(100, "lavoro");
    EXPECT_EQ(user->getAmountFromAccount("lavoro"),"100");
    user->withdrawMoney(50,"lavoro");
    EXPECT_EQ(user->getAmountFromAccount("lavoro"),"50");
}

TEST_F(BankSuit, noMoneyException){
    EXPECT_THROW(user->withdrawMoney(50, "casa"), MovementsException);
}

TEST_F(BankSuit, makeTransfer) {
    auto userB = new User("Marco", "Polo");
    accountManager.createNewAccount(userB, "ufficio");
    user->makeATransfer(50, user->getIbanFromAccount("lavoro"), userB->getIbanFromAccount("ufficio"));
    EXPECT_EQ(user->getAmountFromAccount("lavoro"),"0");
    EXPECT_EQ(userB->getAmountFromAccount("ufficio"), "50");
}

TEST_F(BankSuit, checkAmountOnFile){
    File file;
    std::vector<std::string> data = file.getRowFile(file.openFile(user->getIbanFromAccount("ufficio")));
    EXPECT_EQ(data[data.size()-2], user->getAmountFromAccount("lavoro"));
}

TEST_F(BankSuit, noIbanException){
    EXPECT_THROW(user->makeATransfer(10, user->getIbanFromAccount("lavoro"), "dforfjaiwf"), std::invalid_argument);
}

TEST_F(BankSuit, eqIban){
    EXPECT_THROW(user->makeATransfer(10 ,user->getIbanFromAccount("lavoro"), user->getIbanFromAccount("lavoro")), std::invalid_argument);
}

TEST_F(BankSuit, getAllMovements){
    File* fileClass = new File();
    std::vector<std::string> allMovements = user->getAllMovements("lavoro");
    std::string txt = ".txt";
    std::string fileName = user->getIbanFromAccount("lavoro") + txt;
    std::FILE* file;
    fileClass->openFile(fileName);
    std::vector<std::string> allRow = fileClass->getRowFile(file);
    fileClass->closeFile(file);
    EXPECT_EQ(allMovements[0], allRow[5]);
}