#include "test/vendingmachinetest.h"

#include <iostream>

#include "vendingmachine.h"

using namespace std;

VendingMachineTest::VendingMachineTest()
{
}

void VendingMachineTest::setUp()
{
    vm.pressReturnCoinsButton();
    while(COIN_NONE != vm.checkCoinReturn()){}
    while(PRODUCT_NONE != vm.checkDispenser()){}
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
    setUp();
    return vm.checkDisplay();
}

string VendingMachineTest::insertDimeLikeCoinMachineDisplaysTenCents()
{
    setUp();
    //add a dime-like coin
    insertDimeLikeCoin();
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertNickelLikeCoinMachineDisplaysFiveCents()
{
    setUp();
    //add a nickel-like coin
    insertNickelLikeCoin();
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertQuarterLikeCoinMachineDisplaysTwentyFiveCents()
{
    setUp();
    //add a quarter-like coin
    insertQuarterLikeCoin();
    //check display
    return vm.checkDisplay();
}

string VendingMachineTest::insertInvalidCoinsMachineDisplaysInsertCoin()
{
    setUp();
    //add several bogus coins
    vm.insertCoin(CW_OTHER, CS_OTHER);
    vm.insertCoin(CW_DIME, CS_NICKEL);
    vm.insertCoin(CW_QUARTER, CS_OTHER);
    return vm.checkDisplay();
}

int VendingMachineTest::insertInvalidCoinsCoinReturnHasCoins()
{
    setUp();
    //add several bogus coins
    vm.insertCoin(CW_OTHER, CS_OTHER);
    vm.insertCoin(CW_DIME, CS_NICKEL);
    vm.insertCoin(CW_QUARTER, CS_OTHER);
    int numCoinsReturned = 0;
    while(vm.checkCoinReturn() != COIN_NONE){
        ++numCoinsReturned;
    }
    return numCoinsReturned;
}

int VendingMachineTest::insertValidCoinsPressReturnCoinsCoinReturnHasCoins()
{
    setUp();
    //add several valid coins
    insertDimeLikeCoin();
    insertQuarterLikeCoin();
    insertDimeLikeCoin();
    insertNickelLikeCoin();
    vm.pressReturnCoinsButton();
    int numCoinsReturned = 0;
    while(vm.checkCoinReturn() != COIN_NONE){
        ++numCoinsReturned;
    }
    return numCoinsReturned;
}

bool VendingMachineTest::insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins()
{
    setUp();
    //add several valid coins
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertNickelLikeCoin();
    insertDimeLikeCoin();
    insertDimeLikeCoin();
    vm.pressReturnCoinsButton();

    //coins get returned in reverse order
    if(   vm.checkCoinReturn() == COIN_DIME
       && vm.checkCoinReturn() == COIN_DIME
       && vm.checkCoinReturn() == COIN_NICKEL
       && vm.checkCoinReturn() == COIN_QUARTER
       && vm.checkCoinReturn() == COIN_QUARTER){
        return true;
    }else{
        return false;
    }
}

int VendingMachineTest::insertValidCoinsPressReturnCoinsMachineHasNoCoins()
{
    setUp();
    insertNickelLikeCoin();
    insertDimeLikeCoin();
    insertQuarterLikeCoin();
    vm.pressReturnCoinsButton();
    int numCoinsInMachine = 3;
    while(vm.checkCoinReturn() != COIN_NONE){
        --numCoinsInMachine;
    }
    return numCoinsInMachine;
}

string VendingMachineTest::insertValidCoinsPressReturnCoinsMachineDisplaysInsertCoin()
{
    setUp();
    insertNickelLikeCoin();
    insertNickelLikeCoin();
    insertQuarterLikeCoin();
    vm.pressReturnCoinsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectColaMachineDisplaysColaPrice()
{
    setUp();
    vm.pressSelectColaButton();
    return vm.checkDisplay();

}

string VendingMachineTest::withNoMoneySelectColaCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    setUp();
    vm.pressSelectColaButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectChipsMachineDisplaysChipsPrice()
{
    setUp();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectChipsCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    setUp();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectCandyMachineDisplaysCandyPrice()
{
    setUp();
    vm.pressSelectCandyButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectCandyCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    setUp();
    vm.pressSelectCandyButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectColaMachineDisplaysColaPrice()
{
    setUp();
    insertDimeLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectColaCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    setUp();
    insertDimeLikeCoin();
    vm.pressSelectColaButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectChipsMachineDisplaysChipsPrice()
{
    setUp();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectChipsCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    setUp();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectCandyMachineDisplaysCandyPrice()
{
    setUp();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectCandyCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    setUp();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

PRODUCT VendingMachineTest::withExactChangeSelectColaMachineDispensesCola()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDispenser();
}

string VendingMachineTest::withExactChangeSelectColaMachineDisplaysThankYou()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withExactChangeSelectColaCheckDisplayTwiceMachineDisplaysInsertCoin()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectColaButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

PRODUCT VendingMachineTest::withExactChangeSelectChipsMachineDispensesChips()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDispenser();
}

string VendingMachineTest::withExactChangeSelectChipsMachineDisplaysThankYou()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withExactChangeSelectChipsCheckDisplayTwiceMachineDisplaysInsertCoin()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

PRODUCT VendingMachineTest::withExactChangeSelectCandyMachineDispensesCandy()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertDimeLikeCoin();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    return vm.checkDispenser();
}

string VendingMachineTest::withExactChangeSelectCandyMachineDisplaysThankYou()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertDimeLikeCoin();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withExactChangeSelectCandyCheckDisplayTwiceMachineDisplaysInsertCoin()
{
    setUp();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertDimeLikeCoin();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}
