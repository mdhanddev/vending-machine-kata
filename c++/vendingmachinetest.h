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

    string noCoinsInsertedVendingMachineDisplaysInsertCoin();
    string insertDimeLikeCoinMachineDisplaysTenCents();
    string insertNickelLikeCoinMachineDisplaysFiveCents();
};

#endif // VENDINGMACHINETEST_H
