// Problem: https://leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if(parent[x] != x)
            return parent[x] = find(parent[x]);
        return x;
    }

    void unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);

        if(parentX != parentY) {
            if(size[parentX] >= size[parentY]) {
                size[parentX] += size[parentY];
                parent[parentY] = parentX;
            } else {
                size[parentY] += size[parentX];
                parent[parentX] = parentY;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> result;
        map<string, int> emailGroup;
        int accountsSize = accounts.size();
        
        parent.resize(accountsSize);
        size.resize(accountsSize);

        for (int i = 0; i < accountsSize; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for(int i = 0; i < accountsSize; i++) {
            int accountSize = accounts[i].size();
            for(int j = 1; j < accountSize; j++) {
                string email = accounts[i][j];
                if(emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    unite(i, emailGroup[email]);
                }
            }
        }

        map<int, vector<string>> components;
        for (auto it : emailGroup) {
            components[find(it.second)].push_back(it.first);
        }

        vector<vector<string>> mergedAccounts;
        for (auto it : components) {
            int group = it.first;
            vector<string> component = {accounts[group][0]};
            component.insert(component.end(), it.second.begin(), it.second.end());
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }
    
        return mergedAccounts;
    }
};