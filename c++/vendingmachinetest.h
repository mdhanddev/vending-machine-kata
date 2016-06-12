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

    //use case "Accept Coins"
    string noCoinsInsertedVendingMachineDisplaysInsertCoin();
    string insertDimeLikeCoinMachineDisplaysTenCents();
    string insertNickelLikeCoinMachineDisplaysFiveCents();
    string insertQuarterLikeCoinMachineDisplaysTwentyFiveCents();
    string insertInvalidCoinsMachineDisplaysInsertCoin();
    int insertInvalidCoinsCoinReturnHasCoins();

    //use case "Return Coins"
    int insertValidCoinsPressReturnCoinsCoinReturnHasCoins();
};

#endif // VENDINGMACHINETEST_H
