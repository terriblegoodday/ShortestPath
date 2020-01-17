//
//  main.cpp
//  ShortestPath
//
//  Created by Eduard Dzhumagaliev on 1/17/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#include <iostream>
#include "ShortestPathLib.hpp"
#include "Global.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    ShortestPathLib::AdjacencyList adjacent(MAX);
    ShortestPathLib::Weights weights;
    ShortestPathLib::AdjacencyList &adjacentRef = adjacent;
    ShortestPathLib::Weights &weightsRef = weights;
    ShortestPathLib::readGraphFromFile("test1.txt", adjacentRef, weightsRef);
    ShortestPathLib::Graph graph = {adjacentRef, weightsRef};
    
    std::vector<int> t = ShortestPathLib::shortestPath(graph, 0, 5);
    
    return 0;
}
