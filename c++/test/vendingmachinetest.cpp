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
    vm.coins.clear();
    return vm.checkDisplay();
}

string VendingMachineTest::insertDimeLikeCoinMachineDisplaysTenCents()
{
    //force coins to empty
    vm.coins.clear();
    //add a dime-like coin
    vm.insertCoin(CW_DIME, CS_DIME);
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertNickelLikeCoinMachineDisplaysFiveCents()
{
    //force coins to empty
    vm.coins.clear();
    //add a nickel-like coin
    vm.insertCoin(CW_NICKEL, CS_NICKEL);
    //check display
    return vm.checkDisplay();
}
