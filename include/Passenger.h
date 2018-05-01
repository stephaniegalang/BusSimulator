//
// Created by Thomas + Stephanie on 4/8/18.
//

#ifndef BUSSIMULATOR_PASSENGER_H
#define BUSSIMULATOR_PASSENGER_H
#include "Edge.h"


class Passenger {
    private:
        int origin;
        int dest;
        int creationTime;

    public:

        explicit Passenger(int orig, int creationT=0);
        // void decideOrigin(); Do this in town, then pass in ID

        //below fcn is glitching out, should be void but believes my move fcn returns an int?
        int getOrig();
        int getDest();
        int getStartTime();


};

#endif //BUSSIMULATOR_PASSENGER_H
