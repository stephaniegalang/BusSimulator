#include "Inputs.h"

int main() {
    //TODO: Try to fix so they work in Inputs.h

    // Dynamically generate towns
    for (int i = 1; i <= numTowns; ++i)
        townArray.emplace_back(Town(i,townConnections.at(i - 1).data(),1,10,.25));


    // ------------------generate correct inputs for fwding table generation ------------------
    int** countryIN = new int*[numTowns];
    for (int i = 0; i < numTowns; ++i) {
        countryIN[i] = (townArray.at(i)).getConnections();
    }
    cout << "--Input to forwarding table (arrays of connection speeds)--" << endl;
    for (int i = 0; i < numTowns; ++i)
        cout << countryIN[i][0] << countryIN[i][1] << countryIN[i][2] << countryIN[i][3] << endl;

    // ------------------ Generate forwarding tables in each town ---------------------------------
    for (int i = 0; i < townArray.size(); ++i)
        (townArray.at(i)).generateForwardingTable(countryIN);

    // ------------------ Dynamically generate edges ---------------------------------
    for (int i = 0; i < townConnections.size(); ++i) {
        for (int j = 0; j < sizeof(townConnections.at(i)); ++j)
            if ((townConnections.at(i))[j] != 0)
                roads.push_back(Edge((townConnections.at(i))[j], i, j));
    }

    //int townVerts[2] = {1, 2};
    //Edge edge1(50, 5, 3);
    //Edge edge2(120, townVerts); //create an edge connecting town1 and town2
    //roads.push_back(&edge1);
    //roads.push_back(&edge2);

    Passenger pass1(3);
    Passenger pass2(1);
    Passenger pass3(3);
    Passenger pass4(3);
    townArray.at(1 - 1).addPassenger(pass1);

    townArray.at(2).addPassenger(pass2);
    townArray.at(2).addPassenger(pass3);
    townArray.at(2).addPassenger(pass4);



    for(unsigned int i = 0; i < roads.size(); ++i){
        Edge edge = roads.at(i);
        if ((edge.townLink[0] == 1) && (edge.townLink[1] == 2)){
            std::cout << "The town with ID " << townArray.at(1 - 1).townID << " has access to the town with ID " << townArray.at(2 - 1).townID << "!";
            std::cout << std::endl;
        }
    }





    //town2.TESTmovePeople(&town1);

    delete [] countryIN;
    return 0;
}