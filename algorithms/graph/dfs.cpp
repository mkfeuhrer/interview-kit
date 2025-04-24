#include <bits/stdc++.h>
using namespace std;

/*
* Depth-First Search (DFS)
* Explores as far as possible along each branch before backtracking.
* Uses a stack (implicitly with recursion, or explicitly with an iterative approach).
* Useful for cycle detection, topological sorting, and finding connected components.
* Time Complexity: O(V + E)
* Space Complexity: O(V) (for the recursion stack or explicit stack and visited set)
*/

void dfs(vector<int> adj[], int start, vector<bool> &visited) {
    visited[start] = true;
    cout << start << " ";
    for (int neighbor : adj[start]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, visited);
        }
    }
}

void dfs_iterative(vector<int> adj[], int start) {
    int numVertices = adj.size();
    vector<bool> visited(numVertices, false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    
    while (!s.empty()) {
        int currentNode = s.top();
        cout << currentNode << " ";
        s.pop();
        
        // Add neighbors to stack if not visited
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
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

    vector<bool> visited(5, false);
    dfs(adj, 0, visited);
}