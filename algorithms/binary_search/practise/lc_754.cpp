// Problem:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0, steps = 0;
        while(sum < target || (sum - target) & 1) {
            steps++;
            sum += steps;
        }
        return steps;
    }
};