#include <bits/stdc++.h>
using namespace std;

/*
 * Coin Change
 * Returns the minimum number of coins needed to make the target amount.
 * Commonly used in dynamic programming problems.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
*/

vector<int> dp;

int coin_change(vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (dp[amount] != -1) {
        return dp[amount];
    }
    int minCoins = INT_MAX;
    for (int coin : coins) {
        if (amount - coin >= 0) {
            minCoins = min(minCoins, coin_change(coins, amount - coin));
        }
    }
    dp[amount] = minCoins == INT_MAX ? minCoins : minCoins + 1;
    return dp[amount];
}

int coin_change_tabulation(vector<int>& coins, int amount) {
    dp.assign(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    dp.assign(amount + 1, -1);
    cout << coin_change(coins, amount) << endl;
    cout << coin_change_tabulation(coins, amount) << endl;
    return 0;
}   