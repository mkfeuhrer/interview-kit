// Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans(26), cur(26), res;
        for(char c : p) 
            ans[c - 'a']++;
        
        for(int i = 0; i < s.size(); i++) {
            cur[s[i] - 'a']++;
            if(i >= p.size()) {
                int st = i - p.size();
                cur[s[st] - 'a']--;
            }
                
            if(cur == ans) {
                int st = i - p.size();
                res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
};