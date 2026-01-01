#ifndef OBSERVER_H
#define OBSERVER_H

#include "Stock.h"
using namespace std;

class Observer {
public:
    virtual void onPriceUpdate(const Stock& stock) = 0;
    virtual ~Observer() = default;
};

#endif
