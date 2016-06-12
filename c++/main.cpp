#include <iostream>

#include "vendingmachinetest.h"

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

    //todo
    //use case "Select Product"

    //todo
    //use case "Make Change"

    //todo
    //use case "Return Coins"
    //todo insert N valid coins, press return coins, N coins are in return
    allPass &= harness("insert coins, press return, check coin return", 4, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasCoins());
    allPass &= harness("insert coins, press return, check return for same coins", true, vmt.insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins());
    //todo insert valid coins, press return coins, coins in machine is 0
    allPass &= harness("insert coins, press return, check for coins in machine", 0, vmt.insertValidCoinsPressReturnCoinsMachineHasNoCoins());
    //todo insert valid coins, press return coins, display shows INSERT COIN

    //todo
    //use case "Sold Out"

    //todo
    //use case "Exact Change Only"

    if(allPass) cout << endl << endl << "== all tests passed ==" << endl;
    else cout << endl << endl << "!!" << endl << "!!" << "test failure, check log" << endl << "!!" << endl << "!!" << endl;
}
