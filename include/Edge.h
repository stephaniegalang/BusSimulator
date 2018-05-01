//
// Created by Bora on 4/9/2018.
//

#ifndef BUSSIMULATOR_EDGE_H
#define BUSSIMULATOR_EDGE_H

class Edge {
private:

    int duration; //actual time it takes to travel on this edge, minutes
    int busCount=2;    //number of buses operating on this edge, both ways

public:

    int townLink[2];

    Edge() {duration = 60; townLink[0] = 1, townLink[1] = 1;} //default constructor for an Edge object
    Edge(double baseTime, int town1ID, int town2ID) {duration = baseTime; townLink[0] = town1ID; townLink[1] = town2ID;}
    Edge(double baseTime, int townNodes[2]) {duration = baseTime; townLink[0] = townNodes[0]; townLink[1] = townNodes[1];}
    //Copy constructor for an Edge object

    int getDuration(){  //getter for the current time it takes to travel this edge
        return duration;
    }

    int getBusCount(){
        return busCount;
    }

    void setDuration(double newDuration){ //setter function to change how long it takes to travel this edge
        duration = newDuration;
    }
};



#endif //BUSSIMULATOR_EDGE_H
