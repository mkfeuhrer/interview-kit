// Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getManhattanDistance(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), pointCnt = 0, minCost = 0;
        vector<int> vis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        // iterate until all points are visited - prim's algorithm
        while(pointCnt < n) {
            pair<int, int> top = pq.top();
            pq.pop();

            int weight = top.first, curNode = top.second;
            if(vis[curNode])
                continue;
            
            vis[curNode] = 1;
            pointCnt++;
            minCost += weight;

            for(int i = 0; i < n; i++) {
                // add all the edges of the current node to the priority queue
                if(!vis[i]) {
                    int dis = getManhattanDistance(points[curNode], points[i]);
                    pq.push({dis, i});
                }
            }
        }
        return minCost;
    }
};