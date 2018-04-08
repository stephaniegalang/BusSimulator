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
     double startProb; //likelihood of passenger spawning here at a given time (poisson distribution?)

     //Set of queues for each destination
     //     Keys are ints, one associated with each town
     //     Map to queues of passengers
     //     Used to keep track of riders in each line, as well as which towns are directly connected
     map<int, queue<Passenger*>> destinationQueues;


     //Passenger generator?
     //Dynamic delay function?

 public:
     // Town ID:
     const int townID;

     Town(int id, int* connections, int numConnections, int _basePop, double _startProb);
     void addPassenger(Passenger* pass);
     //pull passengers from departure queue (in another town) into this town
     //void movePassengers(queue<Passenger*> &departures, int numPass );

     //calls target's movePassengers, making it pull passengers from this town
     void TESTmovePeople(Town* target){
         //target->movePassengers(destinationQueues[target->townID],3);
     };

};


#endif //BUSSIMULATOR_TOWN_H
