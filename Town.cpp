//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"
#include "Algorithm.h"

Town::Town(int id, int * connectionsArr, int numConnections, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb}, connections{connectionsArr}{
    for (int i=0; i<numConnections; i++){
        if (connections[i]==townID)
            throw invalid_argument("Town cannot be connected to itself.");
        destinationQueues.emplace(connections[i],queue<Passenger*>());
    }
}

void Town::addPassenger(Passenger pass) {
    cout<<townID<<" Adding passenger. Next stop: "<< pass.getNextStop() <<endl;
//    if(!destinationQueues.count(pass.getNextStop()))
//        throw invalid_argument("Passenger's next stop is not accessible from this town");
}

int* Town::getConnections() {
    return connections;
}

void Town::generateForwardingTable(int** country) {
    forwardingTable = fwdingTable(country, townID);
}

std::vector<int> Town::getConnectedTowns() {
    vector<int> out(forwardingTable.size());
    for (int i=0; i<forwardingTable.size(); i++){ //Iterates through every town ID, if town is connected, gets delay along edge, else puts 0
        if (destinationQueues.count(i)) {
            out[i] = EDGEMAP[vector<int>(townID, i)].getDuration();
        }
        else out[i]=0;
    }
    return connectedTowns;//TODO make sure vector is actually populated
}

int Town::getNextNode(int destID) {
    return forwardingTable[destID];
}

// Moves a bus of passengers from a queue into this town's queues
void Town::movePassengers(queue<Passenger*> &departures, int numPass) {
    for (int i=0; i<numPass && !departures.empty(); i++){
        Passenger* pass=departures.front();
        if (townID==pass->getDest())
            cout<<"Reached dest!"<<endl;// TODO What happens when a passenger reaches destination? (record time taken, start and end nodes, and destroy object)
        else {
            pass->move(); //Updates internal passenger values
            curentPop++;  //Update population (for dynamic traffic)
            if (destinationQueues.count(pass->getNextStop())) //If the next stop is available...
                destinationQueues[pass->getNextStop()].push(pass); //push passenger into the queue
            else
                throw logic_error("The passenger's next stop is not available and this is not the destination.");
        }
        departures.pop();//Removes passenger from previous stop queue
    }
}
