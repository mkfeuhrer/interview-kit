// Problem: https://leetcode.com/problems/house-robber-ii

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int house, vector<int>& nums, vector<int>& dp) {
        if(house < 0) return 0;
        if(dp[house] != -1) return dp[house];
        return dp[house] = max(nums[house] + solve(house-2, nums, dp), solve(house-1, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1), nums1, nums2; 
        for(int i = 0; i < n; i++) {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != n-1) nums2.push_back(nums[i]);
        }

        return max(solve(n - 2, nums1, dp1), solve(n - 2, nums2, dp2));
    }
};