#include "AlertSubscriber.h"
#include <iostream>

AlertSubscriber::AlertSubscriber(LockFreeQueue<Alert>& q)
    : lfQueue(q) {}

void AlertSubscriber::addThreshold(const string& stock, double price) {
    thresholds[stock] = price;
}

void AlertSubscriber::onPriceUpdate(const Stock& stock) {
    if (thresholds.count(stock.symbol) &&
        stock.price >= thresholds[stock.symbol]) {

        Alert alert(
            stock.symbol + " crossed " + to_string(stock.price),
            static_cast<int>(stock.price)
        );

        lock_guard<mutex> lock(mtx);
        alertQueue.push(alert);
    }
}

void AlertSubscriber::processAlerts() {
    lock_guard<mutex> lock(mtx);
    while (!alertQueue.empty()) {
        lfQueue.push(alertQueue.top());
        alertQueue.pop();
    }
}

