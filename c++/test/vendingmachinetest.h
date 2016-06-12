#ifndef VENDINGMACHINETEST_H
#define VENDINGMACHINETEST_H

#include <iostream>

#include "vendingmachine.h"

using namespace std;

class VendingMachineTest
{
public:
    VendingMachineTest();

    VendingMachine vm;

    //helpers
    void cleanMachineState();
    void insertDimeLikeCoin();
    void insertNickelLikeCoin();
    void insertQuarterLikeCoin();

    //use case "Accept Coins"
    string noCoinsInsertedVendingMachineDisplaysInsertCoin();
    string insertDimeLikeCoinMachineDisplaysTenCents();
    string insertNickelLikeCoinMachineDisplaysFiveCents();
    string insertQuarterLikeCoinMachineDisplaysTwentyFiveCents();
    string insertInvalidCoinsMachineDisplaysInsertCoin();
    int insertInvalidCoinsCoinReturnHasCoins();

    //use case "Return Coins"
    int insertValidCoinsPressReturnCoinsCoinReturnHasCoins();
    bool insertValidCoinsPressReturnCoinsCoinReturnHasSameCoins();
    int insertValidCoinsPressReturnCoinsMachineHasNoCoins();
    string insertValidCoinsPressReturnCoinsMachineDisplaysInsertCoin();

    //use case "Select Product"
    string withNoMoneySelectColaMachineDisplaysColaPrice();
    string withNoMoneySelectColaCheckDisplayTwiceMachineDisplaysInsertCoins();
    string withNoMoneySelectChipsMachineDisplaysChipsPrice();
    string withNoMoneySelectChipsCheckDisplayTwiceMachineDisplaysInsertCoins();
    string withNoMoneySelectCandyMachineDisplaysCandyPrice();
    string withNoMoneySelectCandyCheckDisplayTwiceMachineDisplaysInsertCoins();
    string withShortMoneySelectColaMachineDisplaysColaPrice();
    string withShortMoneySelectColaCheckDisplayTwiceMachineDisplaysCurrentTotal();
    string withShortMoneySelectChipsMachineDisplaysChipsPrice();
    string withShortMoneySelectChipsCheckDisplayTwiceMachineDisplaysCurrentTotal();
    string withShortMoneySelectCandyMachineDisplaysCandyPrice();
    string withShortMoneySelectCandyCheckDisplayTwiceMachineDisplaysCurrentTotal();
    PRODUCT withExactChangeSelectColaMachineDispensesCola();
    string withExactChangeSelectColaMachineDisplaysThankYou();
    string withExactChangeSelectColaCheckDisplayTwiceMachineDisplaysInsertCoin();
    PRODUCT withExactChangeSelectChipsMachineDispensesChips();
    string withExactChangeSelectChipsMachineDisplaysThankYou();
    string withExactChangeSelectChipsCheckDisplayTwiceMachineDisplaysInsertCoin();
    PRODUCT withExactChangeSelectCandyMachineDispensesCandy();
    string withExactChangeSelectCandyMachineDisplaysThankYou();
};

#endif // VENDINGMACHINETEST_H
