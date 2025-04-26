// Problem: https://leetcode.com/problems/number-of-enclaves
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xSize, ySize, ans = 0;
    bool vis[505][505];

    void dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= xSize || y < 0 || y >= ySize || vis[x][y]) {
            return;
        }

        vis[x][y] = true;
        // if cell is land, then explore all 4 directions
        if(grid[x][y]) {
            dfs(x+1, y, grid);
            dfs(x, y+1, grid);
            dfs(x-1, y, grid);
            dfs(x, y-1, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
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

        // check for boundary cells and mark walked off cells
        for(int i = 0; i < xSize; i++) {
            if(!vis[i][0] && grid[i][0])
                dfs(i, 0, grid);
            
            if(!vis[i][ySize - 1] && grid[i][ySize-1])
                dfs(i, ySize-1, grid);
        }

        for(int j = 0; j < ySize; j++) {
            if(!vis[0][j] && grid[0][j])
                dfs(0, j, grid);
            
            if(!vis[xSize-1][j] && grid[xSize-1][j])
                dfs(xSize-1, j, grid);
        }

        for(int i=1; i < xSize-1; i++)
            for(int j=1; j < ySize-1; j++)
                if(!vis[i][j] && grid[i][j])
                    ans++;

        return ans;
    }
};