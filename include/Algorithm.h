//
// Created by Stephanie on 4/11/2018.
//
#pragma once
#ifndef BUSSIMULATOR_ALGORITHM_H
#define BUSSIMULATOR_ALGORITHM_H

#include <vector>
#include <climits>
#include <map>

extern const unsigned int numTowns;

std::map <int, int> fwdingTable(int** country, int townID){
    std::map <int, int> forwardingTable;
    forwardingTable.insert(std::pair <int, int> (townID, 0)); // <node, reccomended next node>

    //Initialize Array to store distance from source (could change to map but for now assume index = townID)
    int distances[numTowns];
    int nextNode[numTowns];

    //Initialize tracker for "visited" towns (index = townID)
    bool visitedTowns[numTowns];

    //Initialize towns as infinite distance and unvisited
    for (int i = 0; i < numTowns; i++){
        distances[i] = INT_MAX;
        visitedTowns[i] = false;
    }
    distances[townID - 1] = 0; // Towns min ID is 1, correct indexing
    nextNode[townID - 1] = 0;

    // Calculate shortest paths + closest next node in path for each node
    for (int i = 0; i < numTowns - 1; ++i) {

        // Find min value
        int min = INT_MAX;
        int min_index = townID;

        for (int j = 0; j < numTowns; j++) {
            if (!visitedTowns[j] && (distances[j] <= min)) {
                min = distances[j];
                min_index = j;
            }
        }

        // Mark next closest town as visited
        visitedTowns[min_index] = true;

        // Update distance table, create forwarding table
        for (int j = 0; j < numTowns; j++) {

            if (j == townID - 1) nextNode[j] = - 1; // If node is self, mark next node as 0
            if ((!visitedTowns[j] && country[min_index][j]) && (distances[min_index] != INT_MAX) && ((distances[min_index] + country[min_index][j]) < distances[j])) {
                distances[j] = (distances[min_index] + country[min_index][j]);
                if (townID - 1 == min_index) { // send directly connected nodes directly
                    nextNode[j] = j;
                } else {
                    nextNode[j] = min_index; // send indirectly connected nodes to next node on shortest path
                }
            }

        }
    }

    // Build forwarding table
    std::map <int, int> fwdTable;
    for (int i = 0; i < numTowns; i++) {
        fwdTable.insert(std::pair <int, int> (i+1, nextNode[i]+1));
    }

    //Debugging purposes, print forwarding table using map
    map <int, int> :: iterator itr;
     printf("---Fwding Table Calc for node %d---\n", townID);
    for (itr = fwdTable.begin(); itr != fwdTable.end(); ++itr) {
        printf("next node %d: %d\n", itr->first, itr->second);
    }

    return fwdTable;
}

#endif //BUSSIMULATOR_ALGORITHM_H
