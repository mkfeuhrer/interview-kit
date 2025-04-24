#include <bits/stdc++.h>
using namespace std;

/*
 * Bipartite Graph
 * Checks if a graph can be colored using two colors such that no two adjacent vertices have the same color.
 * Commonly used for graph coloring and bipartite partitioning.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (for the visited set and queue)
 * Useful for graph coloring and bipartite partitioning.
*/ 

bool isBipartite(const std::vector<std::list<int>>& adjList) {
    int numVertices = adjList.size();
    std::vector<bool> visited(numVertices, false);
    std::queue<int> q;
    
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int neighbor : adjList[v]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    } else if (v == neighbor) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    // Sample graph
    std::vector<std::list<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    
    if (isBipartite(adj)) {
        std::cout << "Graph is bipartite." << std::endl;
    } else {
        std::cout << "Graph is not bipartite." << std::endl;
    }
    return 0;
}
