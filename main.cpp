#include "Inputs.h"
#include <random>
#include "Stats.h"

int main() {

    // Dynamically generate towns
    for (int i = 1; i <= numTowns; ++i) {
        TOWNMAP.emplace(i,Town(i, townConnections.at(i - 1).data(), numTowns, 10, .25));
        //TOWNMAP.emplace(i,townArray[i-1]);
    }

    // ------------------generate correct inputs for fwding table generation ------------------
    int** countryIN = new int*[numTowns];
    for (int i = 0; i < numTowns; ++i) {
        countryIN[i] = (TOWNMAP[i+1]).getConnections();
    }
    cout << "--Input to forwarding table (arrays of connection speeds)--" << endl;
    for (int i = 0; i < numTowns; ++i)
        cout << countryIN[i][0] << countryIN[i][1] << countryIN[i][2] << countryIN[i][3] << endl;

    // ------------------ Generate forwarding tables in each town ---------------------------------
    for (int i = 0; i < TOWNMAP.size(); ++i)
        (TOWNMAP[i+1]).generateForwardingTable(countryIN);

    // ------------------ Dynamically generate edges ----------------------------------------------
    for (int i = 0; i < numTowns; ++i) {
        for (int j = 0; j < numTowns; ++j)
            if ((townConnections.at(i))[j] != 0) {
                //auto v =vector<int>(i+1,j+1);
                EDGEMAP[{i+1,j+1}]=Edge((townConnections.at(i))[j], i+1, j+1);
                //TODO: populate globalStats w/ initial values for each pair
                globalStats[{i+1, j+1}] = Stats{.avg = 0, .sum = 0};
            }

    }

    // ------------------- Generate numPassenger many passengers ----------------------------------
    int numPassenger = 20;
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < numPassenger; ++i){
        std::uniform_int_distribution<> dis(1, numTowns);
        int origin = dis(gen);
        auto tmpPass=new Passenger(origin);
        TOWNMAP[origin].addPassenger(tmpPass);
    }

    // ------------------- Actual Simulation Loop ----------------------------------


        //TODO: populate globalStats w/ initial values for each pair (done above)

        //TODO: generate an initial event for each bus (only allow one bus per edge rn)
        // Grab all edges from EDGEMAP key, assume EDGEMAP only has one way edges
    std::vector<Bus> busVec;
    for(map<array<int,2>,Edge>::iterator it = EDGEMAP.begin(); it != EDGEMAP.end(); ++it) {
        busVec.emplace_back(Bus(busCapacity)); // Build as many buses as connections between nodes
        eventList.push(Event{.eventType = Departing, .townID = (it->first)[0], .nextTownID = (it->first)[1], .bus = busVec.back(), .time = 0}) // Walk through each EDGEMAP key to get start, end nodes, initialize to departing
        // Place into corresponding town queues?
    }

        //offset=delay*2/numBuses
        //Departures to start

        //TODO: Event handler loop
    while (numPassengers != 0) {

        for (int i = 0; i < TOWNMAP.size(); ++i) {

        }
        //Loop through each town, check queue
        //while(numPassenger>0)...
        //process next event in queue
        //get town from townID
        //calls appropriate function on town based on event type (pass in event object)
        //DESTROY EVENT
        //add returned event to queue
        //total time taken = time of last event processed;
    }

    // ------------------- Deallocation ----------------------------------
    delete [] countryIN;
    return 0;
}