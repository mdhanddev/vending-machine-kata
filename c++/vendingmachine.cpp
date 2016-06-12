#include "vendingmachine.h"

#include <iostream>
#include <algorithm>

using namespace std;

VendingMachine::VendingMachine()
{
}

string VendingMachine::checkDisplay()
{
    if(coins.empty()) return "INSERT COIN";
    else{
        int total = 0;//in cents
        for_each(coins.begin(), coins.end(), [&total](int &coin){
            if(coin == COIN_DIME) total += 10;
        });
        int cents = total % 100;
        int dollars = total - cents;
        return to_string(dollars)+"."+to_string(cents);

    }
}

void VendingMachine::insertCoin(COIN_WEIGHT cweight, COIN_SIZE csize)
{
    if(cweight == CW_DIME && csize == CS_DIME){
        coins.push_front(COIN_DIME);
    }
}
