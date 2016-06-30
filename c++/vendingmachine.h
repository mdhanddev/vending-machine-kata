#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include <deque>

class VendingMachineTest;

using namespace std;

enum COIN_WEIGHT{
    CW_DIME,
    CW_NICKEL,
    CW_QUARTER,
    CW_OTHER
};
enum COIN_SIZE{
    CS_DIME,
    CS_NICKEL,
    CS_QUARTER,
    CS_OTHER
};
enum COIN{
    COIN_NONE,
    COIN_DIME,
    COIN_NICKEL,
    COIN_QUARTER,
    COIN_INVALID
};

enum PRODUCT{
    PRODUCT_NONE,
    PRODUCT_COLA,
    PRODUCT_CHIPS,
    PRODUCT_CANDY,
    PRODUCT_OTHER
};

class VendingMachine
{
public:
    VendingMachine();

    string checkDisplay();
    PRODUCT checkDispenser();
    COIN checkCoinReturn();

    void insertCoin(COIN_WEIGHT cweight, COIN_SIZE csize);
    void pressReturnCoinsButton();
    void pressSelectColaButton();
    void pressSelectChipsButton();
    void pressSelectCandyButton();

private:
    deque<COIN> coins;
    deque<COIN> coinreturn;
    deque<PRODUCT> dispenser;

    PRODUCT selectedProduct;
    float selectedProductCost;

    static float PRICE_COLA;
    static float PRICE_CHIPS;
    static float PRICE_CANDY;

    static const float VALUE_NICKEL;
    static const float VALUE_DIME;
    static const float VALUE_QUARTER;

    bool productPurchasedSinceLastDisplayCheck = false;

    float insertedCoinTotal();
    void attemptPurchase();
};

#endif // VENDINGMACHINE_H
