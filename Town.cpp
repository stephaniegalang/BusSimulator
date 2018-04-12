//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"

Town::Town(int id, int * connections, int numConnections, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb} {
    for (int i=0; i<numConnections; i++){
        if (connections[i]==townID)
            throw invalid_argument("Town cannot be connected to itself.");
        destinationQueues.emplace(connections[i],queue<Passenger*>());
    }
}

void Town::addPassenger(Passenger pass) {
    cout<<townID<<" Adding passenger. Next stop: "<< pass.getNextStop() <<endl;
    if(!destinationQueues.count(pass.getNextStop()))
        throw invalid_argument("Passenger's next stop is not accessible from this town");
}

// Ask town if it has direct access to a certain town
bool Town::hasDirectAccessTo(int otherTownID) {
    for(auto i = roadsFromTown.begin(); i != roadsFromTown.end(); ++i){
        if ((*i)->hasAccessTo(townID, otherTownID)) { // TODO: find out if edges are start/end only or bidirectional;
            return true;
        }
    }
    return false;
}

std::vector<int> Town::getConnectedTowns(){
    return connectedTowns;
};

void Town::refreshTraffic() {
    forwardingTable.insert(std::pair <int, int> (1, 1));
}

// DOES NOT WORK; DOES NOT UPDATE PASSENGER'S NEXT STOP // TODO: add bus of new passengers to other town's population
/*
void Town::movePassengers(queue<Passenger*> &departures, int numPass) {
    for (int i=0; i<numPass && !departures.empty(); i++){
        Passenger* pass=departures.front();
        if (destinationQueues.count(pass->nextStop))
            destinationQueues[pass->nextStop].push(pass);
        else if (townID==pass->dest)
            cout<<"Reached dest!"<<endl;// TODO What happens when a passenger reaches its destination?
        else
            throw logic_error("The passenger's next stop is not available and this is not the destination.");
        departures.pop();
    }
}
 */
