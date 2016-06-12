#include "vendingmachine.h"

#include <iostream>

using namespace std;

VendingMachine::VendingMachine()
{
}

string VendingMachine::checkDisplay()
{
    if(coins.empty()) return "INSERT COIN";
}
