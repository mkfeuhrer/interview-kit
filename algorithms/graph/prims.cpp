#include <bits/stdc++.h>
using namespace std;

/*
 * Prims Algorithm
 * Finds a minimum spanning tree (MST) for a connected, weighted graph.
 * Uses a priority queue to efficiently select the edge with the smallest weight.
 * Time Complexity: O(E log V) or O(E + V log V) using a min-priority queue.
 * Space Complexity: O(V + E) or O(V) depending on implementation.
*/

void prims(vector<int> adj[], int start) {
    int numVertices = adj.size();
    vector<bool> visited(numVertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Start from the first vertex
    pq.push({0, start});
    
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();
        
        if (visited[currentNode]) continue;
        
        visited[currentNode] = true;
        cout << currentNode << " ";
        
        // Add neighbors to priority queue
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                pq.push({1, neighbor}); // Assuming unit weights (1)
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

    prims(adj, 0);
    return 0;
}