// Problem: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    map<pair<int, int>, vector<int>> mp;

    void solve(TreeNode* root, int step, int level) {
        if(!root) return;        
        mp[{step, level}].push_back(root->val);
        solve(root->left, step-1, level + 1);
        solve(root->right, step+1, level + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);        
        int n = mp.size();
        map<int, vector<int>> ans;
        
        for(auto m: mp) {
            sort(m.second.begin(), m.second.end());
            for(int e: m.second)
                ans[m.first.first].push_back(e);
        }

        vector<vector<int>> res;
        vector<int> tmp;
        for(auto r: ans) {
            tmp.clear();
            if(r.second.size() != 0) {
                for(int j = 0; j < r.second.size(); j++)
                    tmp.push_back(r.second[j]);
                res.push_back(tmp);
            }
            
        }

        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> ans = s.verticalTraversal(root);
    for(auto e: ans) {
        for(int i: e) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}