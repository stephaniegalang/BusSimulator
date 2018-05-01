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

    // ------------------ Dynamically generate edges and route stats ----------------------------------------------
    for (int i = 0; i < numTowns; ++i) {
        for (int j = 0; j < numTowns; ++j){ //For each pair of towns...
            if ((townConnections.at(i))[j] != 0) { //If there is a connection...
                auto tmpEdge = Edge((townConnections.at(i))[j], i + 1, j + 1); //Generate an edge
                EDGEMAP[{i + 1, j + 1}] = tmpEdge; //Add the edge to the map
                if (!EDGEMAP.count({j+1,i+1})){ //If this is the first edge between these two towns...
                    int offset=tmpEdge.getDuration()/tmpEdge.getBusCount(); //Generate a duration to offset the buses by
                    for (int num=0;num < tmpEdge.getBusCount();num++){ //For each bus on this edge, generate an event with the appropriate offset (subsequent events will be generated automatically)
                        eventList.push(Event{num*offset, i+1, j+1, new Bus(), Departing});
                    }
                }
            }
            if (i!=j) //If start and end are different, set starting value for the associated stats
                globalStats[{i + 1, j + 1}] = Stats{0,0};
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

        //TODO: Event handler loop
    while (numPassengers > 0) {
        Event ev = eventList.top(); //get next event
        eventList.pop(); //Remove from queue
        Town t = TOWNMAP[ev.townID];
        if (ev.eventType==Arriving){ //if Arriving
            eventList.push(t.processArrival(ev));
        }else{
            eventList.push(t.processDeparture(ev));
        }
        //delete(&ev); //Delete ev
        //total time taken = time of last event processed;
    }
    cout<<"fffff"<<globalStats[{1,2}].avg<<endl;

    // ------------------- Deallocation ----------------------------------
    delete [] countryIN;
    return 0;
}