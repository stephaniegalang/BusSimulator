//
// Created by thomas on 4/8/18.
//

#include <iostream>
#include "Town.h"

Town::Town(int id, int * connections, int numConnections, int _basePop, double _startProb):
townID{id}, basePop{_basePop}, startProb{_startProb}{
    for (int i=0; i<numConnections; i++){
        if (connections[i]==townID)
            throw invalid_argument("Town cannot be connected to itself.");
        destinationQueues.emplace(connections[i],queue<Passenger*>());
    }
}

void Town::addPassenger(Passenger pass) {
    cout<<townID<<" Adding passenger. Next stop: "<<pass.getNextStop() <<endl;
    if(!destinationQueues.count(pass.getNextStop()))
        throw invalid_argument("Passenger's next stop is not accessible from this town");
}
// DOES NOT WORK; DOES NOT UPDATE PASSENGER'S NEXT STOP // Sounds more realistic to have passenger implement this -s.g.
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
