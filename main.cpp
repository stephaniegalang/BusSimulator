#include <iostream>
#include <vector>
#include "Town.h"
#include "Edge.h"
#include "Bus.h"
#include "Passenger.h"

int main() {
    std::cout << "Hello, World!" << std::endl<<"I'm testing Git." << std::endl;
    std::cout << "Hello, Thomas and Stephanie!" << std::endl << "Hi Bora!" << std::endl;
    std::cout << "Hi group meeting 2" << std:: endl;
    int conn1[]={2,4,3};
    int conn2[]={1,4,3};

    Town town1(1,conn1,3,10,.5);
    Passenger pass1(3);
    Passenger pass2(1);
    Passenger pass3(3);
    Passenger pass4(3);

    town1.addPassenger(pass1);

    Town town2(2,conn2,3,10,.5);
    town2.addPassenger(pass2);
    town2.addPassenger(pass3);
    town2.addPassenger(pass4);

    Bus redRoute(40);
    Bus blueRoute(35);

    std::vector<Edge*> roads; //initialize an array of pointers to Edge objects

    int townVerts[2] = {1, 2};
    Edge edge1(50, 5, 3);
    Edge edge2(120, townVerts); //create an edge connecting town1 and town2

    roads.push_back(&edge1);
    roads.push_back(&edge2);

    for(int i = 0; i < roads.size(); ++i){
        Edge edge = *roads.at(i);
        if ((edge.townLink[0] == 1) && (edge.townLink[1] == 2)){
            std::cout << "The town with ID " << town1.townID << " has access to the town with ID " << town2.townID << " via edge with ID " << edge1.getID() << "!";
            std::cout << std::endl;
        }
    }

    //town2.TESTmovePeople(&town1);
    return 0;
}