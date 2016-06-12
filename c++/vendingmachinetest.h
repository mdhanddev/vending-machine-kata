#ifndef VENDINGMACHINETEST_H
#define VENDINGMACHINETEST_H

#include <iostream>

#include "vendingmachine.h"

using namespace std;

class VendingMachineTest
{
public:
    VendingMachineTest();

    VendingMachine vm;

    //helpers
    void cleanMachineState();
    void insertDimeLikeCoin();
    void insertNickelLikeCoin();
    void insertQuarterLikeCoin();

    //use case "Accept Coins"
    string noCoinsInsertedVendingMachineDisplaysInsertCoin();
    string insertDimeLikeCoinMachineDisplaysTenCents();
    string insertNickelLikeCoinMachineDisplaysFiveCents();
    string insertQuarterLikeCoinMachineDisplaysTwentyFiveCents();
    string insertInvalidCoinsMachineDisplaysInsertCoin();
    int insertInvalidCoinsCoinReturnHasCoins();

    //use case "Return Coins"
    int insertValidCoinsPressReturnCoinsCoinReturnHasCoins();
    bool insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins();
};

#endif // VENDINGMACHINETEST_H
