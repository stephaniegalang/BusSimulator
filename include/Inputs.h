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
unsigned const int numTowns = 4;
std::vector<Town> townArray;
map<vector<int>,Edge> EDGEMAP;
map<int,Town> TOWNMAP;
map<int,int> blankFT;
std::vector<Edge*> roads; //initialize an array of pointers to Edge objects

/*** BEGIN AREAS THAT CAN BE EDITED ***/
// Enter as many connections as there are towns. Array should be numTowns long. Refer to documentation for input details
int conn1[]={0, 3, 0, 0};
int conn2[]={3, 0, 1, 2};
int conn3[]={0, 1, 0, 0};
int conn4[]={0, 2, 0, 0};

int numPassengersTown1 = 4;
int numPassengersTown2 = 4;
int numPassengersTown3 = 4;
int numPassengersTown4 = 4;

/*** END AREAS THAT CAN BE EDITED ***/

// Generate Buses
Bus redRoute(40);
Bus blueRoute(35);

#endif //BUSSIMULATOR_INPUTS_H
