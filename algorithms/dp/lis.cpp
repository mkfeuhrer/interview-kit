#include <bits/stdc++.h>
using namespace std;

/*
 * Longest Increasing Subsequence (LIS)
 * Returns the length of the longest increasing subsequence in the given array.
 * Commonly used in dynamic programming problems.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
*/

vector<int> dp; // dp[i] = length of LIS ending at index i  

int lis(vector<int>& nums) {
    dp.assign(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int lis_binary_search(vector<int>& nums) {
    vector<int> lis;
    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    // example
    // 10 9 2 5 3 7 101 18
    // dp = 1 1 1 2 2 3 4 4
    // lis = 4

    cout << lis(nums) << endl;
    cout << lis_binary_search(nums) << endl;
    return 0;
}
