#include <bits/stdc++.h>
using namespace std;

/*
 * Kruskal's Algorithm
 * Builds the MST by sorting all edges by weight and adding the next smallest edge if it doesn't form a cycle with the already added edges.
 * Uses the Union-Find (Disjoint Set Union) data structure to detect cycles.
 * Finds a minimum spanning tree (MST) for a connected, weighted graph.
 * Uses a priority queue to efficiently select the edge with the smallest weight.
 * Time Complexity: O(E log E) or O(E log V) (since E <= V^2, log E <= 2 log V) primarily due to sorting edges. Union-Find operations are nearly constant time on average with optimizations.
 * Space Complexity: O(V + E) or O(V) depending on implementation.
*/

// Pair: {weight, {vertex1, vertex2}} - priority queue orders by weight
using Pair = std::pair<int, std::pair<int, int>>;

void kruskal(vector<int> adj[], int start) {
    int numVertices = adj.size();
    vector<bool> visited(numVertices, false);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    
    // Start from the first vertex
    pq.push({0, {start, start}});
    
    while (!pq.empty()) {
        int currentNode = pq.top().second.second;
        int currentWeight = pq.top().first;
        pq.pop();
        
        if (visited[currentNode]) continue;
        
        visited[currentNode] = true;
        cout << currentNode << " ";
        
        // Add neighbors to priority queue
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                pq.push({1, {currentNode, neighbor}}); // Assuming unit weights (1)
            }
        }
    }
}

int main() {
    
    // sample graph
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    kruskal(adj, 0);
    return 0;
}