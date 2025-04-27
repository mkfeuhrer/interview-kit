// Problem: https://leetcode.com/problems/valid-triangle-number

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), res = 0;
        for(int i = 0; i < sz; i++) {
           for(int j = i+1, k = j+1; j < (sz - 1) && k <= sz;) {
                if(k == sz || nums[i]+nums[j] <= nums[k]) {
                    if(k > (j+1))
                        res += k - j - 1;
                    j++;
                } else k++;
            }
        }
       return res;
    }
};