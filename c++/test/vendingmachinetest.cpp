#include "vendingmachinetest.h"

#include <iostream>

#include "vendingmachine.h"

using namespace std;

VendingMachineTest::VendingMachineTest()
{
}

string VendingMachineTest::noCoinsInsertedVendingMachineDisplaysInsertCoin()
{
    //force coins to empty
    vm.coins.empty();
    return vm.checkDisplay();
}
