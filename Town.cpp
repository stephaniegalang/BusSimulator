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
    std::vector<Passenger*> &bus = ev.bus.passengers; //pull passengers off bus
    while(!(bus.empty())){
        Passenger* pass=bus.back(); //Pulls passenger off bus
        bus.pop_back();//Removes passenger from bus
        if (townID==pass->getDest()) { //IF passenger is @ destination
            cout << "Reached dest!" << endl;
            Stats &tmp = globalStats[{pass->getOrig(),pass->getDest()}];//update travel statistics
            tmp.avg=tmp.avg*tmp.sum+(ev.time-pass->getStartTime()); //Update avg
            tmp.sum++; //Update total
            delete(pass); //Delete passenger (Decrements numPassengers)
        }
        else { //Updates internal passenger values
            destinationQueues[getNextNode(pass->getDest())].push(pass); // moves passengers into destination queues
        }
        //TODO: Check if this actually removes the element
    }
    return Event{ev.time+waitTime,ev.townID,ev.nextTownID,ev.bus,Departing}; //set up departure
}

//TODO: departure
    //populate bus from corresponding destinationQueue
    //schedule arrival (at opposite node) and return it
        //switch townID and nextTownID
        //offset by edge delay
Event Town::processDeparture(Event ev ){

    auto thisQueue = destinationQueues[ev.nextTownID];
    for(int i = 0 ; i < ev.bus.getCapacity(); ++i){//move passengers from destination queue to bus array
        if (thisQueue.front() != nullptr) {
            Passenger *thisGuy = thisQueue.front();
            ev.bus.passengers.at(i) = thisGuy;
            thisQueue.pop();
        }
    }

    auto edgeTime = EDGEMAP[{ev.nextTownID, ev.townID}].getDuration();

    Event arrivalEvent;

    arrivalEvent.time = edgeTime;
    arrivalEvent.townID = ev.nextTownID;
    arrivalEvent.nextTownID = ev.townID;
    arrivalEvent.bus = ev.bus;
    arrivalEvent.eventType = Arriving;

    return(arrivalEvent);
}
