#include "vendingmachine.h"

#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

float VendingMachine::PRICE_COLA = 1.00;
float VendingMachine::PRICE_CHIPS = 0.50;
float VendingMachine::PRICE_CANDY = 0.65;

const float VendingMachine::VALUE_NICKEL = 0.05;
const float VendingMachine::VALUE_DIME = 0.10;
const float VendingMachine::VALUE_QUARTER = 0.25;

VendingMachine::VendingMachine()
{
    selectedProduct = PRODUCT_NONE;
}

string VendingMachine::checkDisplay()
{
    stringstream ss;

    if(productPurchasedSinceLastDisplayCheck){
        productPurchasedSinceLastDisplayCheck = false;
        return "THANK YOU";
    }else if(selectedProduct != PRODUCT_NONE){
        ss << "PRICE " << fixed << setprecision(2);

        if(selectedProduct == PRODUCT_COLA){
            ss << PRICE_COLA;
        }else if(selectedProduct == PRODUCT_CHIPS){
            ss << PRICE_CHIPS;
        }else if(selectedProduct == PRODUCT_CANDY){
            ss << PRICE_CANDY;
        }

        selectedProduct = PRODUCT_NONE;
    }else if(coins.empty()){
        ss << "INSERT COIN";
    }else{
        float total = insertedCoinTotal();
        ss << fixed << setprecision(2) << total;
    }

    return ss.str();
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
    selectedProductCost = PRICE_COLA;
    attemptPurchase();
}

void VendingMachine::pressSelectChipsButton()
{
    selectedProduct = PRODUCT_CHIPS;
    selectedProductCost = PRICE_CHIPS;
    attemptPurchase();
}

void VendingMachine::pressSelectCandyButton()
{
    selectedProduct = PRODUCT_CANDY;
    selectedProductCost = PRICE_CANDY;
    attemptPurchase();
}

float VendingMachine::insertedCoinTotal()
{
    float total = 0;
    for_each(coins.begin(), coins.end(), [&total](COIN &coin){
        if(coin == COIN_DIME) total += VALUE_DIME;
        if(coin == COIN_NICKEL) total += VALUE_NICKEL;
        if(coin == COIN_QUARTER) total += VALUE_QUARTER;
    });
    return total;
}

void VendingMachine::attemptPurchase()
{
    float total = insertedCoinTotal();
    if(total >= selectedProductCost){
        dispenser.push_front(selectedProduct);
        selectedProduct = PRODUCT_NONE;
        productPurchasedSinceLastDisplayCheck = true;
        coins.clear();
    }
}
