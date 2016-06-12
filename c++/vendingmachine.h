#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include <deque>

class VendingMachineTest;

using namespace std;

class VendingMachine
{
    friend class VendingMachineTest;

public:
    VendingMachine();

    string checkDisplay();

    deque<int> coins;

};

#endif // VENDINGMACHINE_H
