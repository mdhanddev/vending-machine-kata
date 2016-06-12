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

string VendingMachineTest::insertQuarterLikeCoinMachineDisplaysTwentyFiveCents()
{
    //force coins to empty
    vm.coins.clear();
    //add a quarter-like coin
    vm.insertCoin(CW_QUARTER, CS_QUARTER);
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertInvalidCoinsMachineDisplaysInsertCoin()
{
    //force coins to empty
    vm.coins.clear();
    //add several bogus coins
    vm.insertCoin(CW_OTHER, CS_OTHER);
    vm.insertCoin(CW_DIME, CS_NICKEL);
    vm.insertCoin(CW_QUARTER, CS_OTHER);
    return vm.checkDisplay();
}
