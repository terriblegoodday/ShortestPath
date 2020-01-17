//
//  ShortestPathLib.cpp
//  ShortestPath
//
//  Created by Eduard Dzhumagaliev on 1/17/20.
//  Copyright © 2020 Eduard Dzhumagaliev. All rights reserved.
//

#include "ShortestPathLib.hpp"

namespace ShortestPathLib {
    void readGraphFromFile(const char* from, AdjacencyList &adjacent, Weights &weights) {
        
        std::fstream file;
        file.open(from, std::ios::in);
        
        if (file.fail()) {
            throw std::invalid_argument("Failed to read file. Please make sure your filename is right.");
        }
        
        int source, destination;
        size_t distance;
        while (file >> source >> destination >> distance) {
            // source --> destination
            adjacent[source].push_back(destination);
            // destination --> source
            adjacent[destination].push_back(source);
            
            // destination <--> source
            weights[source][destination] = weights[destination][source] = distance;
        }
        
    };

    std::vector<int> shortestPath(Graph graph, int src, int dest) {
        auto [adj, weights] = graph;
        
        size_t n = adj.size();

        std::vector<int> prev(n, -1);
        std::vector<size_t> dist (n, INT_MAX);
        std::vector<bool> visited(n, false);

        auto comp = [&dist](const int& lhs, const int& rhs) -> bool { return dist[lhs] > dist[rhs]; };
        // Define priority queue with `comp` order as priority (vertices with lesser distances take higher priority)
        std::priority_queue<int, std::vector<int>, decltype(comp)> open(comp);

        
        open.push(src);
        dist[src] = 0;
        
        // Here we're computing the routes for **all** vertices
        while(!open.empty()) {
            int next = open.top();
            open.pop();
            if (visited[next])
                continue;
            visited[next] = true;
            for(std::list<int>::const_iterator it = adj[next].begin(); it != adj[next].end(); it++) {
                int neighbor = *it;
                if (!visited[neighbor] && (dist[next] + weights[next][neighbor] < dist[neighbor])) {
                    dist[neighbor] = dist[next] + weights[next][neighbor];
                    prev[neighbor] = next;
                    open.push(neighbor);
                }
            }
        }
        
        // Now we're restoring the path to the `dest` vertex
        int d = dest;
        std::vector<int> path;
        while (d != -1) {
            path.push_back(d);
            d = prev[d];
        }
        // Reverse the path
        std::reverse(path.begin(), path.end());
        
        return path;
    }
}
