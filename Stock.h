#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

struct Stock {
    string symbol;
    double price;
    Stock() : symbol(""), price(0.0) {}
    Stock(string s, double p) : symbol(s), price(p) {}
};

#endif
