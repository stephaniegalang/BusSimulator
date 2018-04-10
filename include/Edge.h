//
// Created by Bora on 4/9/2018.
//

#ifndef BUSSIMULATOR_EDGE_H
#define BUSSIMULATOR_EDGE_H

class Edge {
private:

    double baseDuration;  //original time it takes to travel on this edge, minutes
    int startTownID;
    int endTownID;
    int edgeID;      //TODO combine into one ordered pair for start town and end town, public const
    double duration; //actual time it takes to travel on this edge, minutes
    int busCount;    //number of buses operating on this edge, both ways

public:

    Edge() {baseDuration = 60; startTownID = 1; endTownID = 2; edgeID = 66;} //default constructor for an Edge object
    Edge(double baseTime, int town1ID, int town2ID, int ID) {baseDuration = baseTime; startTownID = town1ID; endTownID = town2ID; edgeID = ID;}
    //Copy constructor for an Edge object

    double getDuration(){  //getter for the current time it takes to travel this edge
        return duration;
    }

    int getID(){
        return edgeID;
    }

    int getBusCount(){
        return busCount;
    }

    void setDuration(double newDuration){ //setter function to change how long it takes to travel this edge
        duration = newDuration;
    }

    void setBusCount(int newCount){
        busCount = newCount;
    }

    void incrementBuses(){ //++ function for when a bus takes this edge
        ++busCount;
    }

    void decrementBuses(){ //-- function for when a bus completes a journey on this edge
        busCount--;
    }

    bool hasAccessTo(int originID, int destID){ //function to check if this edge can take a bus from the town with origin ID to the town with destination ID
        if((startTownID == originID)){
            if ((endTownID == destID)){
                return true; //todo delete this
            }
        }
        return false;
    }

    void takeEdge(){  //function to be called when a bus drives along this edge
        incrementBuses();
        timeCalculate(0.65);
        //wait or simulate for duration many ticks, getDuration();
        decrementBuses();
    }

    void timeCalculate(double trafficCoefficient){ //function to calculate how long a trip along this Edge should take
        setDuration(baseDuration * (trafficCoefficient * getBusCount()));
    }
};



#endif //BUSSIMULATOR_EDGE_H
