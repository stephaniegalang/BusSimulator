#include <iostream>
#include "Town.h"
#include "Edge.h"
#include "Bus.h"

int main() {
    std::cout << "Hello, World!" << std::endl<<"I'm testing Git." << std::endl;
    std::cout << "Hello, Thomas and Stephanie!" << std::endl << "Hi Bora!" << std::endl;
    std::cout << "Hi group meeting 2" << std:: endl;
    int conn1[]={2,4,3};
    int conn2[]={1,4,3};

    Town town1(1,conn1,3,10,.5);
    town1.addPassenger(new Passenger{3,2});

    Town town2(2,conn2,3,10,.5);
    town2.addPassenger(new Passenger{1,1});
    town2.addPassenger(new Passenger{3,1});
    town2.addPassenger(new Passenger{3,4});

    Bus redRoute(1, 40, 1);
    Bus blueRoute(2, 35, 2);
    std::cout << "The bus from the town with ID " << redRoute.getTownID() << " can move " << redRoute.getCapacity() << " passengers!" << std::endl;

    Edge edge1(120, 1, 2, 1); //create an edge connecting town1 and town2

    if (edge1.hasAccessTo(town1.townID, town2.townID)){
        std::cout << "The town with ID " << town1.townID << " has access to the town with ID " << town2.townID << " via edge with ID " << edge1.getID() << "!";
        std::cout << std::endl;
    }

    //town2.TESTmovePeople(&town1);
    return 0;
}