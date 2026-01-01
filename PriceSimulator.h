#ifndef PRICESIMULATOR_H
#define PRICESIMULATOR_H

#include "PricePublisher.h"
#include <vector>
#include <stop_token>
#include <random>
#include <chrono>

using namespace std;

class PriceSimulator {
    PricePublisher& publisher;
    vector<string> symbols;

public:
    PriceSimulator(PricePublisher& p);
    void start(stop_token st);
};

#endif



