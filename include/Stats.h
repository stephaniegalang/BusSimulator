//
// Created by thomas on 4/29/18.
//

#ifndef BUSSIMULATOR_STATS_H
#define BUSSIMULATOR_STATS_H
#include <map>

extern int numPassengers;

struct Stats{
    int sum;
    float avg;
};
extern std::map<std::array<int,2>,Stats> globalStats;



#endif //BUSSIMULATOR_STATS_H
