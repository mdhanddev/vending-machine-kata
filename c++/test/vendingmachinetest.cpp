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

void VendingMachineTest::insertDimeLikeCoin()
{
    vm.insertCoin(CW_DIME, CS_DIME);
}

void VendingMachineTest::insertNickelLikeCoin()
{
    vm.insertCoin(CW_NICKEL, CS_NICKEL);
}

void VendingMachineTest::insertQuarterLikeCoin()
{
    vm.insertCoin(CW_QUARTER, CS_QUARTER);
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
    insertDimeLikeCoin();
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertNickelLikeCoinMachineDisplaysFiveCents()
{
    cleanMachineState();
    //add a nickel-like coin
    insertNickelLikeCoin();
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertQuarterLikeCoinMachineDisplaysTwentyFiveCents()
{
    cleanMachineState();
    //add a quarter-like coin
    insertQuarterLikeCoin();
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

int VendingMachineTest::insertValidCoinsPressReturnCoinsCoinReturnHasCoins()
{
    cleanMachineState();
    //add several valid coins
    insertDimeLikeCoin();
    insertQuarterLikeCoin();
    insertDimeLikeCoin();
    insertNickelLikeCoin();
    vm.pressReturnCoinsButton();
    return vm.coinreturn.size();
}
