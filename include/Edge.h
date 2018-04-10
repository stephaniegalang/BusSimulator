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
    int edgeID;

public:

    double duration; //actual time it takes to travel on this edge, minutes
    int busCount;    //number of buses operating on this edge, both ways

    Edge() {baseDuration = 60; startTownID = 1; endTownID = 2; edgeID = 66;} //default constructor for an Edge object
    Edge(double baseTime, int town1ID, int town2ID, int ID) {baseDuration = baseTime; startTownID = town1ID; endTownID = town2ID; edgeID = ID;}
    //Copy constructor for an Edge object

    double getDuration(){  //getter for the current time it takes to travel this edge
        return duration;
    }

    int getID(){
        return edgeID;
    }

    void setDuration(double newDuration){ //setter function to change how long it takes to travel this edge
        duration = newDuration;
    }

    bool hasAccessTo(int originID, int destID){ //function to check if this edge can take a bus from the town with origin ID to the town with destination ID
        if((startTownID == originID) || (endTownID == originID)){
            if ((startTownID == destID) || (endTownID == destID)){
                return true;
            }
        }
        return false;
    }
};



#endif //BUSSIMULATOR_EDGE_H
