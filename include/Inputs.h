//
// Created by Stephanie on 4/27/2018.
//

#ifndef BUSSIMULATOR_INPUTS_H
#define BUSSIMULATOR_INPUTS_H

#include <iostream>
#include <iomanip>
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
int pasToGenerate = 200;
std::vector<Edge> roads; //initialize an array of pointers to Edge objects

auto compare=[] (Event l, Event r){return (l.time) > (r.time);};
priority_queue<Event,vector<Event>, decltype(compare)> eventList(compare);

/*** BEGIN AREAS THAT CAN BE EDITED ***/
// Enter as many connections as there are towns. Array should be numTowns long. Refer to documentation for input details
unsigned const int numTowns = 4;

std::vector<std::array<int, 4>> townConnections {
        {0, 30, 0, 0},
        {30, 0, 10, 20},
        {0, 10, 0, 0},
        {0, 20, 0, 0}
};


// Generate Bus capacity
int busCapacity = 40;


#endif //BUSSIMULATOR_INPUTS_H
