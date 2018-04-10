//
// Created by Thomas + Stephanie on 4/8/18.
//

#ifndef BUSSIMULATOR_PASSENGER_H
#define BUSSIMULATOR_PASSENGER_H
#include <vector>
#include "Edge.h"

constexpr unsigned int NUMTOWNS = 2;

class Passenger {
    private:
        int origin;
        int dest;
        int travelTime;

        //Path vector is ordered starting with final destination last (due to push/pop nature of vectors)
        //TLDR: Next edge is last item in path
        std::vector<Edge*> path; //rn this is decided when the passenger is generated cuz IRL ppl don't change itineraries

    public:
        int nextStop;
        Passenger(int TownID);
        // void decideOrigin(); Do this in town, then pass in ID

        //below fcn is glitching out, should be void but believes my move fcn returns an int?
        void move(); //Must be called right as town sends passenger to new town; finds final speed + add to travel time, update nextStop/origin, update population in town,
        int getNextStop();
        int getDest();


};

#endif //BUSSIMULATOR_PASSENGER_H
