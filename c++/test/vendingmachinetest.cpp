#include "test/vendingmachinetest.h"

#include <iostream>

#include "vendingmachine.h"

using namespace std;

VendingMachineTest::VendingMachineTest()
{
}

void VendingMachineTest::cleanMachineState()
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
#include <algorithm>
bool VendingMachineTest::insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins()
{
    cleanMachineState();
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
    cleanMachineState();
    insertNickelLikeCoin();
    insertDimeLikeCoin();
    insertQuarterLikeCoin();
    vm.pressReturnCoinsButton();
    return vm.coins.size();
}

string VendingMachineTest::insertValidCoinsPressReturnCoinsMachineDisplaysInsertCoin()
{
    cleanMachineState();
    insertNickelLikeCoin();
    insertNickelLikeCoin();
    insertQuarterLikeCoin();
    vm.pressReturnCoinsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectColaMachineDisplaysColaPrice()
{
    cleanMachineState();
    vm.pressSelectColaButton();
    return vm.checkDisplay();

}

string VendingMachineTest::withNoMoneySelectColaCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    cleanMachineState();
    vm.pressSelectColaButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectChipsMachineDisplaysChipsPrice()
{
    cleanMachineState();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectChipsCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    cleanMachineState();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectCandyMachineDisplaysCandyPrice()
{
    cleanMachineState();
    vm.pressSelectCandyButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withNoMoneySelectCandyCheckDisplayTwiceMachineDisplaysInsertCoins()
{
    cleanMachineState();
    vm.pressSelectCandyButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectColaMachineDisplaysColaPrice()
{
    cleanMachineState();
    insertDimeLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectColaCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    cleanMachineState();
    insertDimeLikeCoin();
    vm.pressSelectColaButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectChipsMachineDisplaysChipsPrice()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectChipsCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectCandyMachineDisplaysCandyPrice()
{
    cleanMachineState();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withShortMoneySelectCandyCheckDisplayTwiceMachineDisplaysCurrentTotal()
{
    cleanMachineState();
    insertNickelLikeCoin();
    vm.pressSelectCandyButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}

PRODUCT VendingMachineTest::withExactChangeSelectColaMachineDispensesCola()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDispenser();
}

string VendingMachineTest::withExactChangeSelectColaMachineDisplaysThankYou()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectColaButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withExactChangeSelectColaCheckDisplayTwiceMachineDisplaysInsertCoin()
{
    cleanMachineState();
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
    cleanMachineState();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDispenser();
}

string VendingMachineTest::withExactChangeSelectChipsMachineDisplaysThankYou()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    return vm.checkDisplay();
}

string VendingMachineTest::withExactChangeSelectChipsCheckDisplayTwiceMachineDisplaysInsertCoin()
{
    cleanMachineState();
    insertQuarterLikeCoin();
    insertQuarterLikeCoin();
    vm.pressSelectChipsButton();
    vm.checkDisplay();
    return vm.checkDisplay();
}
