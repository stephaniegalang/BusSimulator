//
// Created by Bora on 4/9/2018.
//

#ifndef BUSSIMULATOR_BUS_H
#define BUSSIMULATOR_BUS_H


class Bus {
private:

    int capacity;

public:

    std::array<Passenger,capacity> passengers;

    Bus() {capacity = 40; } //default constructor for Bus objects with set values
    Bus(int cap) {capacity = cap;}  //copy constructor for Bus objects
    // current location is set to be the origin town of the bus if not specified

    // busID might be unused depending on implementation of traffic simulation

    int getCapacity(){  //simple getter for capacity of this bus
        return capacity;
    }

};

#endif //BUSSIMULATOR_BUS_H
