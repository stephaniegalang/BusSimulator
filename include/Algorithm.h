//
// Created by Stephanie on 4/11/2018.
//
#pragma once
#ifndef BUSSIMULATOR_ALGORITHM_H
#define BUSSIMULATOR_ALGORITHM_H

#include <vector>
#include "Town.h"

constexpr unsigned int numTowns = 4;

void fwdingTable(int country[numTowns][numTowns], Town* originTown){
    map <int, int> forwardingTable;
    forwardingTable.insert(std::pair <int, int> (originTown->townID, 0)); // <node, reccomended next node>

    //Initialize Array to store distance from source (could change to map but for now assume index = townID)
    int distances[numTowns];

    //Initialize tracker for "visited" towns (index = townID)
    bool visitedTowns[numTowns];

    //Initialize towns as infinite distance and unvisited
    for (int i = 0; i < numTowns; i++){
        distances[i] = INT_MAX;
        visitedTowns[i] = false;
    }
    distances[originTown->townID - 1] = 0; // TODO: if towns start at 1, -1

    // Calculate shortest paths + closest next node in path for each node
    for (int i = 0; i < numTowns - 1; ++i) {

        // Find min value
        int min = INT_MAX;
        int min_index = originTown->townID;

        for (int j = 0; j < numTowns; j++)
            if (!visitedTowns[j] && (distances[j] <= min)) {
                min = distances[j];
                min_index = j;
        }

        // Mark next closest town as visited
        visitedTowns[min_index] = true;

        //
        for (int j = 0; j < numTowns; j++) {
            if ((!visitedTowns[j] && country[min_index][j]) && (distances[min_index] != INT_MAX) && ((distances[min_index] + country[min_index][j]) < distances[j]))
                distances[j] = (distances[min_index] + country[min_index][j]);
        }
    }

    printf("---Fwding Table Calc for node %d---\n", originTown->townID);
    for (int i = 0; i < numTowns; i++)
        printf("dist to node %d: %d\n", i, distances[i]);

    // Build forwarding table

}

#endif //BUSSIMULATOR_ALGORITHM_H
