//
//  ShortestPathTests.m
//  ShortestPathTests
//
//  Created by Eduard Dzhumagaliev on 1/18/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#import <XCTest/XCTest.h>
#include <stdio.h>
#include "ShortestPathLib.hpp"
#include "Global.h"

@interface ShortestPathTests : XCTestCase

@end

@implementation ShortestPathTests

- (void)testGraph1 {
    ShortestPathLib::AdjacencyList adjacent(MAX);
    ShortestPathLib::Weights weights;
    ShortestPathLib::AdjacencyList &adjacentRef = adjacent;
    ShortestPathLib::Weights &weightsRef = weights;
    
    ShortestPathLib::readGraphFromFile("test1.txt", adjacentRef, weightsRef);
    
    ShortestPathLib::Graph graph = {adjacentRef, weightsRef};
    std::vector<int> shouldEqualTo = {0, 1, 5};
    XCTAssertEqual(ShortestPathLib::shortestPath(graph, 0, 5), shouldEqualTo);
}

- (void)testGraph2 {
    ShortestPathLib::AdjacencyList adjacent(MAX);
    ShortestPathLib::Weights weights;
    ShortestPathLib::AdjacencyList &adjacentRef = adjacent;
    ShortestPathLib::Weights &weightsRef = weights;
    
    ShortestPathLib::readGraphFromFile("test1.txt", adjacentRef, weightsRef);
    
    ShortestPathLib::Graph graph = {adjacentRef, weightsRef};
    std::vector<int> shouldEqualTo = {0};
    XCTAssertEqual(ShortestPathLib::shortestPath(graph, 0, 0), shouldEqualTo);
}

- (void)testGraph3 {
    ShortestPathLib::AdjacencyList adjacent(MAX);
    ShortestPathLib::Weights weights;
    ShortestPathLib::AdjacencyList &adjacentRef = adjacent;
    ShortestPathLib::Weights &weightsRef = weights;
    
    ShortestPathLib::readGraphFromFile("test1.txt", adjacentRef, weightsRef);
    ShortestPathLib::Graph graph = {adjacentRef, weightsRef};
    std::vector<int> shouldEqualTo = {0, 1};
    XCTAssertEqual(ShortestPathLib::shortestPath(graph, 0, 1), shouldEqualTo);
}

@end
