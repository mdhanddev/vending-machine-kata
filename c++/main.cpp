#include <iostream>

using namespace std;

#include "vendingmachinetest.h"

template <class T>
bool harness(string testname, T expected, T result){
    if(expected == result){
        cout << "PASS " << testname << endl;
    }else{
        cout << "!!-- FAIL " << testname << ": returned " << result << " when " << expected << " was expected" << endl;
    }
}

int main(int argc, char *argv[])
{
    VendingMachineTest vmt;

    //couple quick and dirty tests to make sure the harness works
    harness("harness pass test", true, true);
    harness("harness fail test", true, false);
    harness("harness type pass test", 3, 3);
    harness("harness type fail test", 3, 5);
}
