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
    //todo insert N valid coins, press return coins, N coins are in return
    allPass &= harness("insert coins, press return, check coin return", 4, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasCoins());
    allPass &= harness("insert coins, press return, check return for same coins", true, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins());
    allPass &= harness("insert coins, press return, check for coins in machine", 0, vmt.insertValidCoinsPressReturnCoinsMachineHasNoCoins());
    allPass &= harness("insert coins, press return, check display", (string)"INSERT COIN", vmt.insertValidCoinsPressReturnCoinsMachineDisplaysInsertCoin());

    //todo
    //use case "Select Product"
    allPass &= harness("no money, select cola, check display", (string)"PRICE 1.00", vmt.withNoMoneySelectColaMachineDisplaysColaPrice());
    allPass &= harness("no money, select cola, check display twice", (string)"INSERT COIN", vmt.withNoMoneySelectColaCheckDisplayTwiceMachineDisplaysInsertCoins());
    allPass &= harness("no money, select chips, check display", (string)"PRICE 0.50", vmt.withNoMoneySelectChipsMachineDisplaysChipsPrice());
    allPass &= harness("no money, select chips, check display twice", (string)"INSERT COIN", vmt.withNoMoneySelectChipsCheckDisplayTwiceMachineDisplaysInsertCoins());
    allPass &= harness("no money, select candy, check display", (string)"PRICE 0.65", vmt.withNoMoneySelectCandyMachineDisplaysCandyPrice());
    //todo no money, press candy, check display twice INSERT COINS
    //todo short money, press cola, check display PRICE 1.00
    //todo short money, press cola, check display twice, shows current total
    //todo short money, press chips, check display PRICE 0.50
    //todo short money, press chips, check display twice, shows current total
    //todo short money, press candy, check display PRICE 0.65
    //todo short money, press candy, check display twice, shows current total
    //todo buy soda with exact change, soda dispensed
    //todo buy soda with exact change, check display THANK YOU
    //todo buy soda with exact change, check display twice INSERT COINS
    //todo buy soda with excess money, soda dispensed
    //todo buy soda with excess money, check display THANK YOU
    //todo buy soda with excess money, check display twice INSERT COINS

    //todo
    //use case "Sold Out"

    //todo
    //use case "Make Change"

    //todo
    //use case "Exact Change Only"

    if(allPass) cout << endl << endl << "== all tests passed ==" << endl;
    else cout << endl << endl << "!!" << endl << "!!" << "test failure, check log" << endl << "!!" << endl << "!!" << endl;

    return(0);
}
