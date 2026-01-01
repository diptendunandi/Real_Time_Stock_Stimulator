#include "PriceSimulator.h"

PriceSimulator::PriceSimulator(PricePublisher& p)
    : publisher(p), symbols({"NTPC", "TCS", "BSE"}) {}

void PriceSimulator::start(stop_token st) {
    default_random_engine gen;
    uniform_real_distribution<double> priceDist(300, 3500);
    uniform_int_distribution<int> stockDist(0, symbols.size() - 1);

    while (!st.stop_requested()) {
        string sym = symbols[stockDist(gen)];
        double price = priceDist(gen);

        publisher.publish(Stock(sym, price));
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}