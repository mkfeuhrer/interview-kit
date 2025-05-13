// Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(!st.empty())
                    st.pop();
                else s[i] = '*';
            }
        }

        while(!st.empty()) {
            int ind = st.top();
            s[ind] = '*';
            st.pop();
        }

        string res;
        for(int i = 0;i < n;i++) {
            if(s[i] != '*')
                res += s[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minRemoveToMakeValid("lee(t(c)o)de)");
    return 0;
}
    