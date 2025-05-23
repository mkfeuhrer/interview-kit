// Problem: https://leetcode.com/problems/graph-valid-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> p;

    bool validTree(int n, vector<vector<int>>& edges) {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (find(a) == find(b)) return 0;
            p[find(a)] = find(b);
            --n;
        }
        return n == 1;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

int main() {
    Solution s;
    cout << s.validTree(5, {{0,1},{0,2},{0,3},{1,4}});
    return 0;
}
