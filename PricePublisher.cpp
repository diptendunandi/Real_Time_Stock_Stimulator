#include "PricePublisher.h"
using namespace std;

void PricePublisher::subscribe(Observer* obs) {
    lock_guard<mutex> lock(mtx);
    observers.push_back(obs);
}

void PricePublisher::publish(const Stock& stock) {
    lock_guard<mutex> lock(mtx);
    for (auto o : observers)
        o->onPriceUpdate(stock);
}
