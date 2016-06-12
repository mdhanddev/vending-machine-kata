#include <iostream>

#include "test/vendingmachinetest.h"

using namespace std;

template <class T>
bool harness(string testname, T expected, T result){
    if(expected == result){
        cout << "PASS " << testname << endl;
        return true;
    }else{
        cout << "!!-- FAIL " << testname << ": returned " << result << " when " << expected << " was expected" << endl;
    }
    return false;
}

int main(int argc, char *argv[])
{
    VendingMachineTest vmt;

    bool allPass(true);

    //use case "Accept Coins"
    allPass &= harness("machine display when no coins inserted", (string)"INSERT COIN", vmt.noCoinsInsertedVendingMachineDisplaysInsertCoin());
    allPass &= harness("machine display on dime", (string)"0.10", vmt.insertDimeLikeCoinMachineDisplaysTenCents());
    allPass &= harness("machine display on nickel", (string)"0.05", vmt.insertNickelLikeCoinMachineDisplaysFiveCents());
    allPass &= harness("machine display on quarter", (string)"0.25", vmt.insertQuarterLikeCoinMachineDisplaysTwentyFiveCents());
    allPass &= harness("machine display on invalid coins", (string)"INSERT COIN", vmt.insertInvalidCoinsMachineDisplaysInsertCoin());
    allPass &= harness("coin return on invalid coins", 3, vmt.insertInvalidCoinsCoinReturnHasCoins());

    //use case "Return Coins"
    allPass &= harness("insert coins, press return, check coin return", 4, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasCoins());
    allPass &= harness("insert coins, press return, check return for same coins", true, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins());
    allPass &= harness("insert coins, press return, check for coins in machine", 0, vmt.insertValidCoinsPressReturnCoinsMachineHasNoCoins());
    allPass &= harness("insert coins, press return, check display", (string)"INSERT COIN", vmt.insertValidCoinsPressReturnCoinsMachineDisplaysInsertCoin());

    //use case "Select Product"
    allPass &= harness("no money, select cola, check display", (string)"PRICE 1.00", vmt.withNoMoneySelectColaMachineDisplaysColaPrice());
    allPass &= harness("no money, select cola, check display twice", (string)"INSERT COIN", vmt.withNoMoneySelectColaCheckDisplayTwiceMachineDisplaysInsertCoins());
    allPass &= harness("no money, select chips, check display", (string)"PRICE 0.50", vmt.withNoMoneySelectChipsMachineDisplaysChipsPrice());
    allPass &= harness("no money, select chips, check display twice", (string)"INSERT COIN", vmt.withNoMoneySelectChipsCheckDisplayTwiceMachineDisplaysInsertCoins());
    allPass &= harness("no money, select candy, check display", (string)"PRICE 0.65", vmt.withNoMoneySelectCandyMachineDisplaysCandyPrice());
    allPass &= harness("no money, select candy, check display twice", (string)"INSERT COIN", vmt.withNoMoneySelectCandyCheckDisplayTwiceMachineDisplaysInsertCoins());
    allPass &= harness("short money, select cola, check display", (string)"PRICE 1.00", vmt.withShortMoneySelectColaMachineDisplaysColaPrice());
    allPass &= harness("short money, select cola, check display twice", (string)"0.10", vmt.withShortMoneySelectColaCheckDisplayTwiceMachineDisplaysCurrentTotal());
    allPass &= harness("short money, select chips, check display", (string)"PRICE 0.50", vmt.withShortMoneySelectChipsMachineDisplaysChipsPrice());
    allPass &= harness("short money, select chips, check display twice", (string)"0.25", vmt.withShortMoneySelectChipsCheckDisplayTwiceMachineDisplaysCurrentTotal());
    allPass &= harness("short money, select candy, check display", (string)"PRICE 0.65", vmt.withShortMoneySelectCandyMachineDisplaysCandyPrice());
    allPass &= harness("short money, select candy, check display twice", (string)"0.05", vmt.withShortMoneySelectCandyCheckDisplayTwiceMachineDisplaysCurrentTotal());
    allPass &= harness("exact change, select cola, cola dispensed", PRODUCT_COLA, vmt.withExactChangeSelectColaMachineDispensesCola());
    allPass &= harness("exact change, select cola, check display", (string)"THANK YOU", vmt.withExactChangeSelectColaMachineDisplaysThankYou());
    allPass &= harness("exact change, select cola, check display twice", (string)"INSERT COIN", vmt.withExactChangeSelectColaCheckDisplayTwiceMachineDisplaysInsertCoin());
    allPass &= harness("exact change, select chips, chips dispensed", PRODUCT_CHIPS, vmt.withExactChangeSelectChipsMachineDispensesChips());
    allPass &= harness("exact change, select chips, check display", (string)"THANK YOU", vmt.withExactChangeSelectChipsMachineDisplaysThankYou());
    allPass &= harness("exact change, select chips, check display twice", (string)"INSERT COIN", vmt.withExactChangeSelectChipsCheckDisplayTwiceMachineDisplaysInsertCoin());
    //todo exact change, select candy, candy dispensed
    allPass &= harness("exact change, select candy, candy dispensed", PRODUCT_CANDY, vmt.withExactChangeSelectCandyMachineDispensesCandy());
    //todo exact change, select candy, check display
    //todo exact change, select candy, check display twice

    //todo
    //use case "Make Change"
    //todo buy soda with excess money, soda dispensed
    //todo buy soda with excess money, check display THANK YOU
    //todo buy soda with excess money, check display twice INSERT COINS

    //todo
    //use case "Sold Out"

    //todo
    //use case "Exact Change Only"

    if(allPass) cout << endl << endl << "== all tests passed ==" << endl;
    else cout << endl << endl << "!!" << endl << "!!" << "test failure, check log" << endl << "!!" << endl << "!!" << endl;

    return(0);
}
