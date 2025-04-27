// Problem: https://leetcode.com/problems/course-schedule

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> vis;

    bool dfs(int i, vector<vector<int>>& adj, unordered_set<int>& set) {
        set.insert(i);
        vis[i] = true;

        for (int num : adj[i]) {
            if (!vis[num]) {
                if (!dfs(num, adj, set))
                    return false;
            } else if (set.count(num)) {
                return false;
            }
        }

        set.erase(i);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courseGraph;
        courseGraph.resize(numCourses);
        vis.resize(numCourses, false);
        
        for(auto prereq: prerequisites) {
            courseGraph[prereq[1]].push_back(prereq[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                unordered_set<int> set;
                if (!dfs(i, courseGraph, set))
                    return false;
            }
        }
        return true;
    }
};