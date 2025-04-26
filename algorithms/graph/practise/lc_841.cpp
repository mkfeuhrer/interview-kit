// Problem: https://leetcode.com/problems/keys-and-rooms/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int vis[1005];
        queue<int> q;

        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            vector<int> keys = rooms[q.front()];
            q.pop();

            for(auto key: keys) {
                if(vis[key]) 
                    continue;
                vis[key] = 1;
                q.push(key);
            }
        }

        for(int i = 0; i < rooms.size(); i++) {
            if(!vis[i])
                return false;
        }
        return true;
    }
};