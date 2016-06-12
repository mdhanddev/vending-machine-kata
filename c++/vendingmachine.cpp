#include "vendingmachine.h"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

VendingMachine::VendingMachine()
{
}

string VendingMachine::checkDisplay()
{
    if(coins.empty()) return "INSERT COIN";
    else{
        float total = 0;//in cents
        for_each(coins.begin(), coins.end(), [&total](int &coin){
            if(coin == COIN_DIME) total += .10;
            if(coin == COIN_NICKEL) total += .05;
        });
        stringstream ss;
        ss << fixed << setprecision(2) << total;
        return ss.str();

    }
}

void VendingMachine::insertCoin(COIN_WEIGHT cweight, COIN_SIZE csize)
{
    if(cweight == CW_DIME && csize == CS_DIME){
        coins.push_front(COIN_DIME);
    }else if(cweight == CW_NICKEL && csize == CS_NICKEL){
        coins.push_front(COIN_NICKEL);
    }
}
