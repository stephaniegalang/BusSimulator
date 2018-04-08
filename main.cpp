#include <iostream>
#include "Town.h"

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

    //town2.TESTmovePeople(&town1);
    return 0;
}