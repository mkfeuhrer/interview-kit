// Problem: https://leetcode.com/problems/132-pattern

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int last = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] < last) return true;
            while(!st.empty() && st.top() < nums[i]) {
                last = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};