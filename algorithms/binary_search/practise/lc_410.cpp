// Problem: https://leetcode.com/problems/split-array-largest-sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int sum, vector<int>& nums, int m) {
        int n = nums.size(), count = 0, val = 0;
        for(int i = 0; i < n; i++) {
            if(val + nums[i] > sum) {
                val = nums[i];
                m--;
                if(m < 0) 
                    return false;
            } else
                val+= nums[i];
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sum = 0, low = 0, high, mid, ans = 0;
        for(auto num: nums) {
            sum+=num;
            low = max(low, num);
        }
        high = sum;
        while(low < high) {
            mid = low + (high - low)/2;
            // cout << low << " " << high << " " << mid << endl;
            if(check(mid, nums, m-1))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};