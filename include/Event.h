//
// Created by thomas on 4/29/18.
//

#ifndef BUSSIMULATOR_EVENT_H
#define BUSSIMULATOR_EVENT_H

#include "Bus.h"

enum Mode{Arriving,Departing};
struct Event{
    long time;
    int townID, nextTownID;
    Bus bus;
    Mode eventType;
};
#endif //BUSSIMULATOR_EVENT_H
