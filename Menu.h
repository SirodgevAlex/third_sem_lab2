#pragma once;

#include <iostream>

using namespace std;

void DataTypeMenu() {
    cout << "What data type you want?" << '\n';
    cout << "1 - int" << '\n';
    cout << "2 - float" << '\n';
    cout << "3 - complex " << '\n';
}

void CommandMenu() {
    cout << "What do you want to do?\n";
    cout << "1 - Input backpack\n";
    cout << "2 - Input elements\n";
    cout << "3 - Print backpack\n";
    cout << "4 - Print elements\n";
    cout << "5 - Maximize sum of costs and sum of volumes <= volume of backpack\n";
    cout << "6 - Maximize sum of costs and sum of volumes <= volume of backpack and sum of weights <= weight of backpack\n";
    cout << "7 - Maximize sum of costs and sum of volumes, sum of volumes <= volume of backpack and sum of weights <= weight of backpack\n";
    cout << "8 - Maximize sum of costs, minimize sum of weights, sum of volumes <= volume of backpack and sum of weights <= weight of backpack\n";
    cout << "9 - Test\n";
    cout << "0 - Stop\n";
}