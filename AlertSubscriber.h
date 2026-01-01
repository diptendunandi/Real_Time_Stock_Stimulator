#ifndef ALERTSUBSCRIBER_H
#define ALERTSUBSCRIBER_H

#include "Observer.h"
#include "Alert.h"
#include "LockFreeQueue.h"
#include <queue>
#include <mutex>
#include <unordered_map>

using namespace std;

class AlertSubscriber : public Observer {
    unordered_map<string, double> thresholds;  // per-stock thresholds
    priority_queue<Alert> alertQueue;
    LockFreeQueue<Alert>& lfQueue;
    mutex mtx;

public:
    AlertSubscriber(LockFreeQueue<Alert>& q);
    void addThreshold(const string& stock, double price);
    void onPriceUpdate(const Stock& stock) override;
    void processAlerts();
};

#endif

