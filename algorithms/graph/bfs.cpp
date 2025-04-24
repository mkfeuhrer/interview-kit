#include <bits/stdc++.h>
using namespace std;

/*
 * BFS: Breadth First Search
 * Explores the graph level by level.
 * Uses a queue to manage vertices to visit.
 * Guaranteed to find the shortest path in terms of number of edges for unweighted graphs.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (for the queue and visited set)
*/

void bfs(vector<int> adj[], int start) {
    int numVertices = adj.size();
    queue<int> q;
    vector<bool> visited(numVertices, false);

    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int currentNode = q.front();
        cout << currentNode << " ";
        
        // Remove current node from queue
        q.pop();

        // Add neighbors to queue if not visited
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    bfs(adj, 5);
}