#include <bits/stdc++.h>

/*
 * Strongly Connected Components (SCC)
 * Finds groups of vertices in a directed graph where every vertex is reachable from every other vertex in the group.
 * Commonly used for finding strongly connected components in graphs.
 * Time Complexity: O(V + E)
 * Space Complexity: O(V) (for the stack and visited set)
 * Useful for finding strongly connected components in graphs.
*/
 
void dfs(const std::vector<std::list<int>>& adjList, int v, std::vector<bool>& visited, std::stack<int>& s) {
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited, s);
        }
    }
    s.push(v);
}

void sccUtil(const std::vector<std::list<int>>& adjList, int v, std::vector<bool>& visited, std::stack<int>& s) {
    visited[v] = true;
    std::cout << v << " ";
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            sccUtil(adjList, neighbor, visited, s);
        }
    }
}

void findSCCs(const std::vector<std::list<int>>& adjList) {
    int numVertices = adjList.size();
    std::vector<bool> visited(numVertices, false);
    std::stack<int> s;
    
    // Step 1: Perform DFS and push vertices to stack
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            dfs(adjList, i, visited, s);
        }
    }
    
    // Step 2: Reset visited
    std::fill(visited.begin(), visited.end(), false);
    
    // Step 3: Perform DFS on reversed graph
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (!visited[v]) {
            std::cout << "SCC: ";
            sccUtil(adjList, v, visited, s);
            std::cout << std::endl;
        }
    }
}

int main() {
    // Sample graph
    std::vector<std::list<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(0);
    
    findSCCs(adj);
    return 0;
}