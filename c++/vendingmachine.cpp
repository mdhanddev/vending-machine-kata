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
    if(productPurchasedSinceLastDisplayCheck){
        productPurchasedSinceLastDisplayCheck = false;
        return "THANK YOU";
    }else if(selectedProduct == PRODUCT_COLA){
        selectedProduct = PRODUCT_NONE;
        return "PRICE 1.00";
    }else if(selectedProduct == PRODUCT_CHIPS){
        selectedProduct = PRODUCT_NONE;
        return "PRICE 0.50";
    }else if(selectedProduct == PRODUCT_CANDY){
        selectedProduct = PRODUCT_NONE;
        return "PRICE 0.65";
    }else if(coins.empty()){
        return "INSERT COIN";
    }else{
        float total = insertedCoinTotal();
        stringstream ss;
        ss << fixed << setprecision(2) << total;
        return ss.str();
    }
}

PRODUCT VendingMachine::checkDispenser()
{
    if(dispenser.empty()) return PRODUCT_NONE;
    else {
        PRODUCT prod = dispenser.at(0);
        dispenser.pop_front();
        return prod;
    }
}

COIN VendingMachine::checkCoinReturn()
{
    if(coinreturn.empty()) return COIN_NONE;
    else{
        COIN coin = coinreturn.at(0);
        coinreturn.pop_front();
        return coin;
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
    float total = insertedCoinTotal();
    if(total >= 1.00){
        dispenser.push_front(PRODUCT_COLA);
        selectedProduct = PRODUCT_NONE;
        productPurchasedSinceLastDisplayCheck = true;
        coins.clear();
    }
}

void VendingMachine::pressSelectChipsButton()
{
    selectedProduct = PRODUCT_CHIPS;
    float total = insertedCoinTotal();
    if(total >= 0.50){
        dispenser.push_front(PRODUCT_CHIPS);
        productPurchasedSinceLastDisplayCheck = true;
    }
}

void VendingMachine::pressSelectCandyButton()
{
    selectedProduct = PRODUCT_CANDY;
}

float VendingMachine::insertedCoinTotal()
{
    float total = 0;
    for_each(coins.begin(), coins.end(), [&total](COIN &coin){
        if(coin == COIN_DIME) total += .10;
        if(coin == COIN_NICKEL) total += .05;
        if(coin == COIN_QUARTER) total += .25;
    });
    return total;
}
