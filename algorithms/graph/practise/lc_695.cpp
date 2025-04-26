// Problem: https://leetcode.com/problems/max-area-of-island

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int xSize, ySize, ans = 0;
    bool vis[55][55];

    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= xSize || y < 0 || y >= ySize || grid[x][y] == 0 || vis[x][y])
            return 0;

        vis[x][y] = true;
        int curArea = 0;
        // if cell is land, then explore all 4 directions
        if(grid[x][y]) {
            curArea = 1;
            curArea += dfs(x+1, y, grid);
            curArea += dfs(x, y+1, grid);
            curArea += dfs(x-1, y, grid);
            curArea += dfs(x, y-1, grid);
        }
        return curArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        xSize = grid.size();
        if(xSize == 0)
            return 0;
        ySize = grid[0].size();

        // Initialize visited array to false
        for (int i = 0; i < xSize; ++i) {
            for (int j = 0; j < ySize; ++j) {
                vis[i][j] = false;
            }
        }

        for(int i = 0; i < xSize; i++) {
            for(int j = 0; j < ySize; j++) {
                if(!vis[i][j] && grid[i][j])
                    ans = max(ans, dfs(i, j, grid));
            }
        }

        return ans;
    }
};