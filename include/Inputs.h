//
// Created by Stephanie on 4/27/2018.
//

#ifndef BUSSIMULATOR_INPUTS_H
#define BUSSIMULATOR_INPUTS_H

#include <iostream>
#include <vector>
#include "Town.h"
#include "Edge.h"
#include "Bus.h"
#include "Passenger.h"
#include "Event.h"
#include "Stats.h"

//TODO: Tidy

/* Storage */
std::vector<Town> townArray;
map<array<int,2>,Edge> EDGEMAP;
map<array<int,2>,Stats> globalStats;
map<int,Town> TOWNMAP;
int numPassengers=0;
std::vector<Edge> roads; //initialize an array of pointers to Edge objects

auto compare=[] (Event l, Event r){return (l.time) > (r.time);};
priority_queue<Event,vector<Event>, decltype(compare)> eventList();

/*** BEGIN AREAS THAT CAN BE EDITED ***/
// Enter as many connections as there are towns. Array should be numTowns long. Refer to documentation for input details
unsigned const int numTowns = 4;

std::vector<std::array<int, 4>> townConnections {
        {0, 3, 0, 0},
        {3, 0, 1, 2},
        {0, 1, 0, 0},
        {0, 2, 0, 0}
};

std::vector<int> numPassengersTown {
    4,
    4,
    4,
    4
};

// Generate Bus capacity
int busCapacity = 40;
//Bus Route1_2_1(40);  //Format: Route<startNode>_<endNode>_<busNum>
//Bus Route3_2_1(40);
//Bus Route4_2_1(40);
//int numBuses = 3;

/*** END AREAS THAT CAN BE EDITED ***/

/* Place inputs into arrays to allow dynamic initialization based on number */
struct Thing {
    int m_i, m_j;
    Thing(int i, int j) : m_i(i), m_j(j) {}
};


#endif //BUSSIMULATOR_INPUTS_H
