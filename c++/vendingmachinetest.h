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
};

#endif // VENDINGMACHINETEST_H
