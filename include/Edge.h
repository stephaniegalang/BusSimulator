//
// Created by Bora on 4/9/2018.
//

#ifndef BUSSIMULATOR_EDGE_H
#define BUSSIMULATOR_EDGE_H

class Edge {
private:

    int baseDuration;  //original time it takes to travel on this edge, minutes
    int duration; //actual time it takes to travel on this edge, minutes
    int busCount=2;    //number of buses operating on this edge, both ways

public:

    int townLink[2];

    //Edge() {baseDuration = 60; townLink[0] = 1, townLink[1] = 1;} //default constructor for an Edge object
    Edge(double baseTime, int town1ID, int town2ID) {baseDuration = baseTime; townLink[0] = town1ID; townLink[1] = town2ID;}
    Edge(double baseTime, int townNodes[2]) {baseDuration = baseTime; townLink[0] = townNodes[0]; townLink[1] = townNodes[1];}
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

    void timeCalculate(double trafficCoefficient){ //function to calculate how long a trip along this Edge should take
        setDuration(baseDuration * (trafficCoefficient * getBusCount()));
    }
};



#endif //BUSSIMULATOR_EDGE_H
