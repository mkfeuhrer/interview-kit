// Problem: https://leetcode.com/problems/number-of-islands
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[305][305], n, m;
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if(row == n || col == m || row < 0 || col < 0) return;
        if(vis[row][col] == 1) return;
        vis[row][col] = 1;
        if(grid[row][col] == '1') {
            dfs(row + 1, col, grid);
            dfs(row - 1, col, grid);
            dfs(row, col + 1, grid);
            dfs(row, col - 1, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};