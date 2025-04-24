#include <bits/stdc++.h>
using namespace std;

/*
 * Cycle Detection
 * Detects cycles in a graph using DFS or BFS.
 * Commonly used for cycle detection in graphs.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (for the stack and visited set)
*/

bool isCyclicUtil(const std::vector<std::list<int>>& adjList, int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor] && isCyclicUtil(adjList, neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(const std::vector<std::list<int>>& adjList) {
    int numVertices = adjList.size();
    std::vector<bool> visited(numVertices, false);
    std::vector<bool> recStack(numVertices, false);
    
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && isCyclicUtil(adjList, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Sample graph
    std::vector<std::list<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    
    if (isCyclic(adj)) {
        std::cout << "Graph contains a cycle." << std::endl;
    } else {
        std::cout << "Graph does not contain a cycle." << std::endl;
    }
    return 0;
}