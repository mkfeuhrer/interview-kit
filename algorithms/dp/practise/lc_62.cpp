// Problem: https://leetcode.com/problems/unique-paths

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[105][105];
    
    int solve(int x, int y, int m, int n) {
        if(x == m-1 && y == n-1) return 1;
        if(x == m || y == n) return 0;
        if(dp[x][y]) return dp[x][y];
        return dp[x][y] = solve(x+1, y, m, n) + solve(x, y+1, m, n);
    }
    
    int uniquePaths(int m, int n) {
        return solve(0, 0, m , n);
    }
};