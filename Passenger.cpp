//
// Created by Stephanie on 4/9/2018.
//

#include "Passenger.h"
#include <random>

class Town; // Forward declare town to allow use of town's path forwarding table

// Passenger initialized in a specific town
Passenger::Passenger(int TownID): origin{TownID}, travelTime(0) {
    //Generate random destination; Reference: http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, NUMTOWNS);
    dest = dis(gen);

    // TODO: routing algorithm to determine path based on dest
    // recursive fcn: check if have access to town
    // find all edges with startTown = origin, place in vector
    //      check "has access to", prefer direct routes
    //      else recurse thro each end town, need check to avoid previously visited towns
    //          if reach dead end, return large distance to guarantee it's never used
    // needed variables: vec of towns visited, vec of distances, vec of potential paths?

}

void Passenger::move(){
    //TODO: update movement conditions based on town and edge class updates
    //      travelTime += (path.at(path.end() + 0)).getDuration(); // update time travelled from edge's travel time
    //      origin = (path.at(path.end() + 0)).getEndTown(); //
    //      path.pop_back(); // remove road travelled from path
    //      town.incPop(); // update new town's population // dont in town
}

int Passenger::getNextStop(){
    //return (path.at(path.end() + 0)).getEndTown();
    return 3;
}

int Passenger::getDest(){
    return dest;
}