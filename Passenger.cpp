//
// Created by Stephanie on 4/9/2018.
//

#include "Passenger.h"
#include <random>
#include "EdgeMap.h"
#include "TownMap.h"

class Town; // Forward declare town to allow use of town's path forwarding table

// Passenger initialized in a specific town
Passenger::Passenger(int TownID): origin{TownID}, travelTime(0) {
    //Generate random destination; Reference: http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, NUMTOWNS);
    dest = dis(gen);

    //TODO: generate nextStop from forwarding tables
    // temp nextStop set to 0
    nextStop = 1;
}

void Passenger::move(){
    //TODO: update movement conditions based on town and edge class updates
    travelTime += EDGEMAP[std::vector<int>(currentStop,nextStop)].getDuration(); // update time travelled from edge's travel time
    currentStop=nextStop;
    nextStop=TOWNMAP[currentStop].getNextNode(dest);
}

int Passenger::getNextStop(){
    //return (path.at(path.end() + 0)).getEndTown();
    return nextStop;
}

int Passenger::getDest(){
    return dest;
}