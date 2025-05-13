// Problem: https://leetcode.com/problems/diagonal-traverse-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = 0;
        map<int, vector<int>> mp;
        vector<int> ans;
        int maxCol = 0;
        for(auto num: nums) {
            if(maxCol < num.size())
                maxCol = num.size();
        }
        n = maxCol;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < nums[i].size(); j++)
                mp[i+j].push_back(nums[i][j]);

        for(auto me: mp) {
            vector<int> tmp = me.second;
            reverse(tmp.begin(), tmp.end());
            for(auto e: tmp) {
                ans.push_back(e);
            }                
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = s.findDiagonalOrder(nums);
    for(auto e: ans) {
        cout << e << " ";
    }
    return 0;
}