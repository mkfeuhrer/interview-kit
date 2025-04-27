// Problem: https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGraphBipartite;
    vector<bool> vis;
    vector<int> color;

    void dfs(int node, int currentColor, vector<vector<int>>& graph) {
        if(vis[node])
            return;
        
        vis[node] = true;
        color[node] = currentColor;
        for(int i = 0; i < graph[node].size(); i++) {
            int neighbour = graph[node][i];
            if(color[neighbour] == color[node])
                isGraphBipartite = false;
            dfs(graph[node][i], !currentColor, graph);
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        isGraphBipartite = true;
        vis.resize(sz, false);
        color.resize(sz, false);

        for(int i = 0; i < sz; i++)
            color[i] = -1;
        
        for(int i = 0; i < sz; i++)
            if(color[i] == -1)
                dfs(i, 0, graph);

        return isGraphBipartite;
    }
};