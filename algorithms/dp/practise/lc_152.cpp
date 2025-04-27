// Problem: https://leetcode.com/problems/maximum-product-subarray

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            left =  (left ? left : 1) * nums[i];
            right =  (right ? right : 1) * nums[n - 1 - i];
            ans = max(ans, max(left, right));
        }
        return ans;
    }
};