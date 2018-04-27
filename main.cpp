#include <iostream>
#include <vector>
//#include "Algorithm.h"
#include "Town.h"
#include "Inputs.h"

int main() {

    // Generate towns
    Town town1(1,conn1,1,10,.25);
    townArray.push_back(town1);
    Town town2(2,conn2,2,10,.25);
    townArray.push_back(town2);
    Town town3(3,conn3,1,10,.25);
    townArray.push_back(town3);
    Town town4(4,conn4,1,10,.25);
    townArray.push_back(town4);

    // Populate forwarding table input

    // ------------------ pseudocode to generate correct inputs for fwding table generation ------------------
    // generate shell for input array
    int** countryIN = new int*[numTowns];
    for (int i = 0; i < numTowns; ++i) {
        countryIN[i] = (townArray.at(i)).getConnections();
    }
    cout << "--Input to forwarding table (arrays of connection speeds)--" << endl;
    for (int i = 0; i < numTowns; ++i)
    cout << countryIN[i][0] << countryIN[i][1] << countryIN[i][2] << countryIN[i][3] << endl;
//    // populate input array
//    for (int i = 0; i < numTowns; ++i) {
//        int* townDistArr = (townArray.at(i)).getConnections(); // array w/ distances to other towns
//
//        // place vector values into input array
//        for (int j = 0; j < numTowns; ++j) {
//            countryIN[i][j] = townDistArr.at(j);
//            //temp: fill with all 1's
//            //countryIN[i][j] = 1;
//        }
//    }

    //delete dynamically allocated countryIN
//    for(int i = 0; i < numTowns; ++i) {
//        delete [] countryIN[i];
//    }

    // ------------------ end input generation -------------------------------------------------------------
    for (int i = 0; i < townArray.size(); ++i)
        (townArray.at(i)).generateForwardingTable(countryIN);

    Passenger pass1(3);
    Passenger pass2(1);
    Passenger pass3(3);
    Passenger pass4(3);
//    town1.addPassenger(pass1);


    town2.addPassenger(pass2);
    town2.addPassenger(pass3);
    town2.addPassenger(pass4);

    int townVerts[2] = {1, 2};
    Edge edge1(50, 5, 3);
    Edge edge2(120, townVerts); //create an edge connecting town1 and town2

    roads.push_back(&edge1);
    roads.push_back(&edge2);

    for(unsigned int i = 0; i < roads.size(); ++i){
        Edge edge = *roads.at(i);
        if ((edge.townLink[0] == 1) && (edge.townLink[1] == 2)){
            std::cout << "The town with ID " << town1.townID << " has access to the town with ID " << town2.townID << "!";
            std::cout << std::endl;
        }
    }





    //town2.TESTmovePeople(&town1);

    delete [] countryIN;
    return 0;
}