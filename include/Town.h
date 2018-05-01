//
// Created by thomas on 4/8/18.
//

#ifndef BUSSIMULATOR_TOWN_H
#define BUSSIMULATOR_TOWN_H
#include <queue>
#include <map>
#include "Passenger.h"
#include "EdgeMap.h"
#include "Event.h"
#include "Stats.h"

extern unsigned const int numTowns;
// Forward Declarations from Algorithm
int recursiveTownSearch(int otherTown, std::vector<int>* visitedTowns);
int nextNodeToDest(int originID, int destID, std::vector<int>* visitedTowns);

using namespace std;

 class Town {
 private:
     int waitTime=5;
     int basePop;
     //int curentPop;
     double startProb; //likelihood of passenger spawning here at a given time (poisson distribution?)
     int* connections;
     std::vector<int> connectedTowns;
     map <int, int> forwardingTable; // <otherTown, recommended edge to other town>

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

     //Pass in vector of connected towns and the edge objects associated with them, as well as an  empty forwarding table
     Town(int id, int* connectionsArr, int numConnections, int _basePop, double _startProb);
     Town():townID{0}{};
     void addPassenger(Passenger* pass);
     //pull passengers from departure queue (in another town) into this town
     void movePassengers(queue<Passenger*> &departures, int numPass );

     //calls target's movePassengers, making it pull passengers from this town
     void TESTmovePeople(Town* target){
         //target->movePassengers(destinationQueues[target->townID],3);
     };


     //Node 0 has connectedTowns = {0, 4, 3, 0};
     //0 for itself or nodes it cannot see (0 and 3)
     //>0 for directly connected nodes; [Node 1] is 4 away, [Node 2] is 3 away
     int* getConnections();
     void generateForwardingTable(int** country);
     //int getNextNode();
     int getNextNode(int destID);//used by passenger to get next node

     Event processArrival(Event ev);
     Event processDeparture(Event ev);


};


#endif //BUSSIMULATOR_TOWN_H
