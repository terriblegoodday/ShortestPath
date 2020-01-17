//
//  ShortestPathLib.hpp
//  ShortestPath
//
//  Created by Eduard Dzhumagaliev on 1/17/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#ifndef ShortestPathLib_hpp
#define ShortestPathLib_hpp

#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>

namespace ShortestPathLib {
    typedef std::vector<std::list<int> > AdjacencyList;
    typedef std::unordered_map<int, std::unordered_map<int, size_t> > Weights;
    typedef std::pair<AdjacencyList&, Weights&> Graph;

    /**
     Used to read **unidirectional** graph from file with name `from` to std::pair with address &to
     @param from file from which to read the graph
     @param adjacent to which write adjacent vertices
     @param weights to which write weights (distances) between vertices
     */
    void readGraphFromFile(const char* from, AdjacencyList &adjacent, Weights &weights);

    /**
     Used to find shortest paths to all the vertices which can be reached through the `src` vertex.
     @discussion It can be optimized to seek distance only for the destination (requring to add `int dest` argument)
     @param graph std::pair with adjacency list and weights' hash map (matrix)
     @param src Source vertex from which the distances are calculated
     @return vector with the shortest paths for all vertices (you need restore the path manually by going through all vertices in the path in an inverse order)
     */
    std::vector<int> shortestPath(Graph graph, int src, int dest);
}
#endif /* ShortestPathLib_hpp */
