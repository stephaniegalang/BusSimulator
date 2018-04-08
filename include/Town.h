//
// Created by thomas on 4/8/18.
//

#ifndef BUSSIMULATOR_TOWN_H
#define BUSSIMULATOR_TOWN_H
#include <queue>
#include <map>
#include "Passenger.h"


using namespace std;
 class Town {
 private:
     int basePop;
     int curentPop;
     //Passenger generator?
     //Dynamic delay function?

 public:
     //Set of queues for each destination
     //     Keys are ints, one associated with each town
     //     Map to queues of passengers
     //     Used to keep track of riders in each line, as well as which towns are directly connected
     map<int, queue<Passenger>> DestinationQueues;

     Town();

};


#endif //BUSSIMULATOR_TOWN_H
