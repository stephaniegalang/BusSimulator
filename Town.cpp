//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"

Town::Town(int id, int * connectedTowns, int numConnectedTowns, vector<Edge*> &edges, map<int, int> fTable, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb}, roadsFromTown{edges} , forwardingTable{fTable}{
    for (int i=0; i<numConnectedTowns; i++){
        if (connectedTowns[i]==townID)
            throw invalid_argument("Town cannot be connected to itself.");
        destinationQueues.emplace(connectedTowns[i],queue<Passenger*>());
    }
}

void Town::addPassenger(Passenger pass) {
    cout<<townID<<" Adding passenger. Next stop: "<< pass.getNextStop() <<endl;
    if(!destinationQueues.count(pass.getNextStop()))
        throw invalid_argument("Passenger's next stop is not accessible from this town");
}


void Town::refreshTraffic() {
    forwardingTable.insert(std::pair <int, int> (1, 1)); // TODO: Shouldn't this function just refresh the travel times?
}

void Town::addRoad(Edge* edge) {
    if (edge->townLink[0]!=townID) throw invalid_argument("Edge does not originate at this town");
    roadsFromTown.push_back(edge);
    connectedTowns.push_back(edge->townLink[1]);
    destinationQueues.emplace(edge->townLink[1], queue<Passenger*>());
    // TODO: update forwarding table w/ new information
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
        if (destinationQueues.count(pass->nextStop))
            destinationQueues[pass->nextStop].push(pass);
        else if (townID==pass->getDest())
            cout<<"Reached dest!"<<endl;// TODO What happens when a passenger reaches destination?
        else
            throw logic_error("The passenger's next stop is not available and this is not the destination.");
        departures.pop(); //Removes passenger from previous stop queue
    }
}
