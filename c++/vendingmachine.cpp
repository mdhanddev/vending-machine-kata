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
    if(selectedProduct == PRODUCT_COLA){
        selectedProduct = PRODUCT_NONE;
        return "PRICE 1.00";
    }else if(selectedProduct == PRODUCT_CHIPS){
        return "PRICE 0.50";
    }else if(coins.empty()){
        return "INSERT COIN";
    }else{
        float total = 0;//in cents
        for_each(coins.begin(), coins.end(), [&total](int &coin){
            if(coin == COIN_DIME) total += .10;
            if(coin == COIN_NICKEL) total += .05;
            if(coin == COIN_QUARTER) total += .25;
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
    }else if(cweight == CW_QUARTER && csize == CS_QUARTER){
        coins.push_front(COIN_QUARTER);
    }else{
        coinreturn.push_front(COIN_INVALID);
    }
}

void VendingMachine::pressReturnCoinsButton()
{
    coinreturn.insert(coinreturn.end(), coins.begin(), coins.end());
    coins.clear();
}

void VendingMachine::pressSelectColaButton()
{
    selectedProduct = PRODUCT_COLA;
}

void VendingMachine::pressSelectChipsButton()
{
    selectedProduct = PRODUCT_CHIPS;
}
