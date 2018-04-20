//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"

Town::Town(int id, int * connections, int numConnections, map<int, int> fTable, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb}, forwardingTable{fTable}{
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

std::vector<int> Town::getConnectedTowns() {
    return connectedTowns;
}

int Town::getNextNode(int destID) {
    return forwardingTable[destID];
}

// Moves a bus of passengers from a queue into this town's queues
void Town::movePassengers(queue<Passenger*> &departures, int numPass) {
    for (int i=0; i<numPass && !departures.empty(); i++){
        Passenger* pass=departures.front();
        pass->move(); //Updates internal passenger values
        curentPop++;
        if (destinationQueues.count(pass->getNextStop()))
            destinationQueues[pass->getNextStop()].push(pass);
        else if (townID==pass->getDest())
            cout<<"Reached dest!"<<endl;// TODO What happens when a passenger reaches destination?
        else
            throw logic_error("The passenger's next stop is not available and this is not the destination.");
        departures.pop(); //Removes passenger from previous stop queue
    }
}
