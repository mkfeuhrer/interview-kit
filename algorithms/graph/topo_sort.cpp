#include <bits/stdc++.h>
using namespace std;

/*
 * Topological Sort
 * Orders vertices in a directed acyclic graph (DAG) such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.
 * Commonly used for scheduling tasks, dependency resolution, and ordering vertices in a graph.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (for the stack and visited set)
 * Useful for task scheduling, dependency resolution.
*/

void topologicalSortUtil(const std::vector<std::list<int>>& adjList, int v, std::vector<bool>& visited, std::stack<int>& s) {
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(adjList, neighbor, visited, s);
        }
    }
    s.push(v);
}

void topologicalSort(const std::vector<std::list<int>>& adjList) {
    int numVertices = adjList.size();
    std::vector<bool> visited(numVertices, false);
    std::stack<int> s;
    
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(adjList, i, visited, s);
        }
    }
    
    // Print the topological order
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Sample graph
    std::vector<std::list<int>> adj(5);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);

    topologicalSort(adj);
    return 0;
}