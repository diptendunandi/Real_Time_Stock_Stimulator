#ifndef PRICEPUBLISHER_H
#define PRICEPUBLISHER_H

#include "Observer.h"
#include <vector>
#include <mutex>

using namespace std;

class PricePublisher {
    vector<Observer*> observers;
    mutex mtx;

public:
    void subscribe(Observer* obs);
    void publish(const Stock& stock);
};

#endif

