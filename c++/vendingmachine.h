#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include <deque>

class VendingMachineTest;

using namespace std;

enum COIN_WEIGHT{
    CW_DIME,
    CW_NICKEL,
    CW_OTHER
};
enum COIN_SIZE{
    CS_DIME,
    CS_NICKEL,
    CS_OTHER
};
enum COIN{
    COIN_DIME,
    COIN_NICKEL,
    COIN_INVALID
};

class VendingMachine
{
    friend class VendingMachineTest;

public:
    VendingMachine();

    string checkDisplay();
    void insertCoin(COIN_WEIGHT cweight, COIN_SIZE csize);

    deque<int> coins;

};

#endif // VENDINGMACHINE_H
