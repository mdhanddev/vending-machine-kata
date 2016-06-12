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
    friend class VendingMachineTest;

public:
    VendingMachine();

    string checkDisplay();
    void insertCoin(COIN_WEIGHT cweight, COIN_SIZE csize);
    void pressReturnCoinsButton();
    void pressSelectColaButton();
    void pressSelectChipsButton();
    void pressSelectCandyButton();

private:
    deque<int> coins;
    deque<int> coinreturn;

    PRODUCT selectedProduct;
};

#endif // VENDINGMACHINE_H
