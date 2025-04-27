// Problem: https://leetcode.com/problems/house-robber

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int solve(int house, vector<int>& nums) {
        if(house < 0)
            return 0;
        
        if(dp[house] != -1) 
            return dp[house];

        return dp[house] = max(nums[house] + solve(house-2, nums), solve(house-1, nums));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return solve(nums.size() - 1, nums);
    }
};