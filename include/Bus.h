//
// Created by Bora on 4/9/2018.
//

#ifndef BUSSIMULATOR_BUS_H
#define BUSSIMULATOR_BUS_H


class Bus {
private:

    int capacity;
    int townID;  //townID of town that owns this bus
    int busID;   //identifier for Buses, might be unnecessary
    int currentTownID; //townID of town where bus currently is

public:

    Bus() {capacity = 40; townID = 1; currentTownID = 1; busID = 1;} //default constructor for Bus objects with set values
    Bus(int originID, int cap, int ID) { capacity = cap; townID = originID; currentTownID = originID; busID = ID; }  //copy constructor for Bus objects
    // current location is set to be the origin town of the bus if not specified

    // busID might be unused depending on implementation of traffic simulation

    int getCapacity(){  //simple getter for capacity of this bus
        return capacity;
    }

    int getTownID(){   //simple getter for the town ID of this bus
        return townID;
    }

    int getCurrentLocation(){  //getter to locate the bus, if need be
        return currentTownID;
    }

    int setCurrentLocation(int current){
        currentTownID = current;
    }

    bool isInTown(int town){ //function to check if this Bus is in specified town
        return(currentTownID == town);
    }

};

#endif //BUSSIMULATOR_BUS_H
