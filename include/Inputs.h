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

/* Storage */
std::vector<Town> townArray;
//std::vector<int*> townConnections;
map<vector<int>,Edge> EDGEMAP;
map<int,Town> TOWNMAP;
std::vector<Edge> roads; //initialize an array of pointers to Edge objects

/*** BEGIN AREAS THAT CAN BE EDITED ***/
// Enter as many connections as there are towns. Array should be numTowns long. Refer to documentation for input details
unsigned const int numTowns = 4;

std::vector<std::array<int, 4>> townConnections {
        {0, 3, 0, 0},
        {3, 0, 1, 2},
        {0, 1, 0, 0},
        {0, 2, 0, 0}
};

int numPassengersTown1 = 4;
int numPassengersTown2 = 4;
int numPassengersTown3 = 4;
int numPassengersTown4 = 4;

// Generate Buses
Bus City1Route(40);
Bus City2Route(40);
Bus City3Route(40);
Bus City4Route(40);

/*** END AREAS THAT CAN BE EDITED ***/

/* Place inputs into arrays to allow dynamic initialization based on number */
struct Thing {
    int m_i, m_j;
    Thing(int i, int j) : m_i(i), m_j(j) {}
};


#endif //BUSSIMULATOR_INPUTS_H
