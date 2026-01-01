#ifndef ALERT_H
#define ALERT_H

#include <string>
using namespace std;

struct Alert {
    string message;
    int priority;

    Alert() : message(""), priority(0) {}
    Alert(string m, int p) : message(m), priority(p) {}
};

// Inline fixes multiple definition
inline bool operator<(const Alert& a, const Alert& b) {
    return a.priority < b.priority;
}

#endif


