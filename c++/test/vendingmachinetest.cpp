#include "vendingmachinetest.h"

#include <iostream>

#include "vendingmachine.h"

using namespace std;

VendingMachineTest::VendingMachineTest()
{
}

void VendingMachineTest::cleanMachineState()
{
    vm.coins.clear();
    vm.coinreturn.clear();
}

string VendingMachineTest::noCoinsInsertedVendingMachineDisplaysInsertCoin()
{
    cleanMachineState();
    return vm.checkDisplay();
}

string VendingMachineTest::insertDimeLikeCoinMachineDisplaysTenCents()
{
    cleanMachineState();
    //add a dime-like coin
    vm.insertCoin(CW_DIME, CS_DIME);
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertNickelLikeCoinMachineDisplaysFiveCents()
{
    cleanMachineState();
    //add a nickel-like coin
    vm.insertCoin(CW_NICKEL, CS_NICKEL);
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertQuarterLikeCoinMachineDisplaysTwentyFiveCents()
{
    cleanMachineState();
    //add a quarter-like coin
    vm.insertCoin(CW_QUARTER, CS_QUARTER);
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertInvalidCoinsMachineDisplaysInsertCoin()
{
    cleanMachineState();
    //add several bogus coins
    vm.insertCoin(CW_OTHER, CS_OTHER);
    vm.insertCoin(CW_DIME, CS_NICKEL);
    vm.insertCoin(CW_QUARTER, CS_OTHER);
    return vm.checkDisplay();
}

int VendingMachineTest::insertInvalidCoinsCoinReturnHasCoins()
{
    cleanMachineState();
    //add several bogus coins
    vm.insertCoin(CW_OTHER, CS_OTHER);
    vm.insertCoin(CW_DIME, CS_NICKEL);
    vm.insertCoin(CW_QUARTER, CS_OTHER);
    return vm.coinreturn.size();
}
