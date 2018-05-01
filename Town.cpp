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
    cout<<townID<<" Adding passenger. Next stop: "<< getNextNode(pass->getDest())<<endl;
    destinationQueues[getNextNode(pass->getDest())].push(pass);
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

//TODO: Test arrival
Event Town::processArrival(Event ev) {
    std::vector<Passenger*> &bus = ev.bus->passengers; //pull passengers off bus
    while(!(bus.empty())){
        Passenger* pass=bus.back(); //Pulls passenger off bus
        bus.pop_back();//Removes passenger from bus
        if (townID==pass->getDest()) { //IF passenger is @ destination
            cout << "Reached dest!" << endl;
            Stats &tmp = globalStats[{pass->getOrig(),pass->getDest()}];//update travel statistics
            tmp.avg=(tmp.avg*tmp.numPas+(ev.time-pass->getStartTime()))/(++tmp.numPas); //Update avg and total passengers
            delete(pass); //Delete passenger (Decrements numPassengers)
        }
        else { //Updates internal passenger values
            destinationQueues[getNextNode(pass->getDest())].push(pass); // moves passengers into destination queues
        }
        //TODO: Check if this actually removes the element
    }
    return Event{ev.time+waitTime,ev.townID,ev.nextTownID,ev.bus,Departing}; //set up departure
}

//TODO: Test departure
Event Town::processDeparture(Event ev ){

    auto thisQueue = destinationQueues[ev.nextTownID]; //get departing queue
    for(int i = 0 ; i < ev.bus->getCapacity(); ++i){//move passengers from destination queue to bus array
        if (thisQueue.empty()) break; //If no people waiting, stop loading
        ev.bus->passengers.push_back(thisQueue.front()); //Move passenger to bus
        thisQueue.pop(); //Remove passenger from stop
    }

    auto edgeTime = EDGEMAP.at({ev.nextTownID, ev.townID}).getDuration(); // get travel time to next town (from this node to that)

    Event arrivalEvent{ev.time+edgeTime,ev.nextTownID,ev.townID,ev.bus,Arriving}; //Create next arrival event, swap townID and NextTownID

    return(arrivalEvent);
}
