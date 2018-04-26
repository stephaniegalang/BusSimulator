//
// Created by Thomas + Stephanie on 4/8/18.
//

#ifndef BUSSIMULATOR_PASSENGER_H
#define BUSSIMULATOR_PASSENGER_H
#include "Edge.h"

constexpr unsigned int NUMTOWNS = 2;

class Passenger {
    private:
        int origin;
        int dest;
        int travelTime;
        int currentStop;
        int nextStop;

    public:

        explicit Passenger(int TownID);
        // void decideOrigin(); Do this in town, then pass in ID

        //below fcn is glitching out, should be void but believes my move fcn returns an int?
        void move(); //Must be called right as town sends passenger to new town; adds edge duration to travel time, update nextStop
        int getNextStop();
        int getDest();


};

#endif //BUSSIMULATOR_PASSENGER_H
