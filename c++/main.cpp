#include <iostream>

#include "vendingmachinetest.h"

using namespace std;

template <class T>
bool harness(string testname, T expected, T result){
    if(expected == result){
        cout << "PASS " << testname << endl;
    }else{
        cout << "!!-- FAIL " << testname << ": returned " << result << " when " << expected << " was expected" << endl;
    }
}

int main(int argc, char *argv[])
{
    VendingMachineTest vmt;

    //use case "Accept Coins"
    harness("machine display when no coins inserted", (string)"INSERT COIN", vmt.noCoinsInsertedVendingMachineDisplaysInsertCoin());
    harness("machine display on dime", (string)"0.10", vmt.insertDimeLikeCoinMachineDisplaysTenCents());
    harness("machine display on nickel", (string)"0.05", vmt.insertNickelLikeCoinMachineDisplaysFiveCents());
    //todo inserting nickel (and check display)
    //todo inserting quarter (and check display)
    //todo inserting invalid coin (and check display)

    //todo
    //use case "Select Product"

    //todo
    //use case "Make Change"

    //todo
    //use case "Return Coins"

    //todo
    //use case "Sold Out"

    //todo
    //use case "Exact Change Only"
}
