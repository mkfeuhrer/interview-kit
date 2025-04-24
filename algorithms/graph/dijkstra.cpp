#include <bits/stdc++.h>
using namespace std;


/*
* Dijkstra's Algorithm
* Finds the shortest path from a single source vertex to all other vertices in a graph with non-negative edge weights.
* Uses a priority queue to efficiently select the vertex with the smallest known distance.
* Time Complexity: O(E log V) or O(E + V log V) using a min-priority queue.
* Space Complexity: O(V + E) or O(V) depending on implementation.
*/

void dijkstra(vector<int> adj[], int start) {
    int numVertices = adj.size();
    vector<int> dist(numVertices, INT_MAX);
    dist[start] = 0;
    
    // Priority queue to store the current distance and vertex
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();
        
        // Skip if we have already processed this node
        if (currentDist > dist[currentNode]) continue;
        
        // Explore neighbors
        for (int neighbor : adj[currentNode]) {
            int neighborDist = currentDist + 1; // Assuming unit weights (1)
            if (neighborDist < dist[neighbor]) {
                dist[neighbor] = neighborDist;
                pq.push({neighborDist, neighbor});
            }
        }
    }
    
    // Print the shortest distances
    for (int i = 0; i < numVertices; ++i) {
        cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    // sample graph
    vector<int> adj[5];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    dijkstra(adj, 0);
    return 0;
}
