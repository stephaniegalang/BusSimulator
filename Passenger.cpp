//
// Created by Stephanie on 4/9/2018.
//

#include "Passenger.h"
#include <random>
#include "EdgeMap.h"
#include "TownMap.h"
#include <iostream>

class Town; // Forward declare town to allow use of town's path forwarding table
//extern unsigned int numTowns;


// Passenger initialized in a specific town
Passenger::Passenger(int TownID, int creationT): origin{TownID}, creationTime(creationT) {
    //Generate random destination; Reference: http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, numTowns);
    dest = dis(gen);
    while(TownID == dest){
        dest = dis(gen);
    }
    numPassengers++;
    if (origin==1)cout<<dest<<endl;

}



int Passenger::getOrig(){
    return origin;
}
int Passenger::getDest(){
    return dest;
}
int Passenger::getStartTime() {
    return creationTime;
}