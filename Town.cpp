//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"
#include "Algorithm.h"

Town::Town(int id, int * connectionsArr, int numConnections, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb}, connections{connectionsArr}{
    for (int i=0; i<numConnections; i++){
        if (connections[i]>0)
            destinationQueues.emplace(i+1,queue<Passenger*>());
    }
}

void Town::addPassenger(Passenger* pass) {
    cout<<townID<<" Adding passenger. Next stop: "<< pass->getNextStop() <<endl;
    destinationQueues[pass->getNextStop()].push(pass);
}

int* Town::getConnections() {
    return connections;
}

void Town::generateForwardingTable(int** country) {
    forwardingTable = fwdingTable(country, townID);
}


int Town::getNextNode(int destID) {
    return forwardingTable[destID];
}

// Moves a bus of passengers from a queue into this town's queues
//TODO: delete
void Town::movePassengers(queue<Passenger*> &departures, int numPass) {
    for (int i=0; i<numPass && !departures.empty(); i++){
        Passenger* pass=departures.front();
        if (townID==pass->getDest())
            cout<<"Reached dest!"<<endl;// TODO What happens when a passenger reaches destination? (record time taken, start and end nodes, and destroy object)
        else {
            pass->move(); //Updates internal passenger values
            //curentPop++;  //Update population (for dynamic traffic)
            destinationQueues[pass->getNextStop()].push(pass); //push passenger into the queue
        }
        departures.pop();//Removes passenger from previous stop queue
    }
}

//TODO: Arrival
    //pull passengers off bus
        // moves passengers into destination queues
        // make sure bus seats are empty (set bus contents to nulls))
        //handle passenger updates
        //IF passenger is @ destination
            //update travel statistics
                //update sum and mean travel time for this start/end pair
            //delete passenger
            //--totalPassengers
    //Schedule departure for bus (offset by waitTime) and return it

//TODO: departure
    //populate bus from corresponding destinationQueue
    //schedule arrival (at opposite node) and return it
        //switch townID and nextTownID
        //offset by edge delay

