// Problem: https://leetcode.com/problems/diagonal-traverse-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> ans;

        for(int step = 0; step < m+n-1; step++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if( (i+j) % n == step) {
                        mp[i+j].push_back(mat[i][j]);
                    }
                }
            }
        }

        for(auto me: mp) {
            vector<int> tmp = me.second;
            if(me.first %2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            for(auto e: tmp) {
                ans.push_back(e);
            }                
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = s.findDiagonalOrder(mat);
    for(auto e: ans) {
        cout << e << " ";
    }
    return 0;
}
