/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <vector> 

using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+10];

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};
// @lc code=end

// define the problem
// climb(i) ways to climb hight i
// climb(i) = climb(i-1) + climb(i-2)