#include "PricePublisher.h"
#include "AlertSubscriber.h"
#include "PriceSimulator.h"
#include "LockFreeQueue.h"
#include "Alert.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {
    PricePublisher publisher;
    LockFreeQueue<Alert> lfQueue(100);

    // Create subscribers
    AlertSubscriber trader1(lfQueue);
    AlertSubscriber trader2(lfQueue);
    AlertSubscriber trader3(lfQueue);

    // Configure thresholds
    trader1.addThreshold("NTPC", 120);
    trader1.addThreshold("TCS", 150);


    trader2.addThreshold("NTPC", 360);
    trader2.addThreshold("BSE", 2640);

    trader3.addThreshold("TCS", 3250);
    trader3.addThreshold("BSE", 2660);

    // Subscribe
    publisher.subscribe(&trader1);
    publisher.subscribe(&trader2);
    publisher.subscribe(&trader3);

    // Start simulator
    PriceSimulator simulator(publisher);

    jthread simThread([&](stop_token st) {
        simulator.start(st);
    });

    // Alert processor
    jthread processor([&](stop_token st) {
        while (!st.stop_requested()) {
            trader1.processAlerts();
            trader2.processAlerts();
            trader3.processAlerts();

            Alert a;
            while (lfQueue.pop(a)) {
                cout << "[ALERT] " << a.message<< " priority=" << a.priority << endl;
            }
            this_thread::sleep_for(chrono::milliseconds(300));
        }
    });

    this_thread::sleep_for(chrono::seconds(10));
    cout << "Stopping simulation..." << endl;
    return 0;
}
