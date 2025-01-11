/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start

// return fewest coins as possible | -1 
// infinite coins for each type of coin
// 
// Lets define the problems and then try to generalize it
// i: index of coins; m the target money left
// find(i, m) return the number of coins we need to use with coins[i::end] for money m

// recurrence relation:
// take = find(i, m-coins[i])
// skip = find(i+1, m)
// if take == -1 && skip == -1 -> dp[i][m] = -1; find(i, m) = -1
// else if take == -1 -> dp[i][m] = skip; find(i, m) = skip
// else if skip == -1 -> dp[i][m] = take + 1; find(i, m) = take + 1
// else take++; find(i,m) = min(take, skip)

// time comp:
// coins.size() == N, amount == M
// O(N*M)

// [998, 990, 10, 1, 1]  1000
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -2)); // around 400 kb in memory

        return find(0, amount, coins, dp);
    }
private:
    int find(int i, int m, vector<int>& coins, vector<vector<int>>& dp){
        // base cases
        if (m < 0) return -1;
        if (i >= coins.size() && m > 0) return -1;
        if (m == 0) return 0;

        if (dp[i][m] != -2) return dp[i][m];

        int take = find(i, m-coins[i], coins, dp);
        int skip = find(i+1, m, coins, dp);
        if (take == -1 && skip == -1) {
            dp[i][m] = -1;
            return -1;
        } else if (take == -1){
            dp[i][m] = skip;
            return skip;
        } else if (skip == -1){
            dp[i][m] = take + 1;
            return take + 1;
        } else {
            take++;
            dp[i][m] = min(take, skip);
            return min(take, skip);
        }
    }
};
// @lc code=end

