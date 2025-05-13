// Problem: https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') 
            return;
        board[i][j] = '*';
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) 
            return;    
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(i, 0, board);
            dfs(i, n - 1, board);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, board);
            dfs(m - 1, j, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == '*') 
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);
    for(auto e: board) {
        for(auto e1: e) {
            cout << e1 << " ";
        }
        cout << endl;
    }
    return 0;
}