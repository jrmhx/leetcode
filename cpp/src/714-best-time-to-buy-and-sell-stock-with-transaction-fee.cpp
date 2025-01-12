/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for (int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            
            dp[i][1] = max(dp[i-1][1],dp[i][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

// you must sell the stock before you buy again.
// only on fee for D(i, j)
// no short selling, (no sell before buy in)

// dp[i][j] max profit in for prices[::i] we can buy and prices[::j] we can sell
// bounds: i -> [0, n]; j -> [i, n]
// for each vaild tuple D(i, j) we can make 2 decisions:
//      1. based on CON_1 good for a deal : we make a deal on this tuple (buy at prices[i] and sell at prices[j])
//      2. based on CON_2 not good for a deal: we dont make a deal
// the dp[i][j] will be updated based on what decision we make for each D(i, j)


// for each price in prices we can buy:
//     for each possible day we can sell:
//         ifDealProf = prices[j] - prices[i] - fee
//         GOOD_DEAL_CON = ifDealProf > 0
//         if GOOD_DEAL_CON == true:
//             dp[i][j] = dp[i-1][i-1] + ifDealProf
//         else if GOOD_DEAL_CON == false:
//             dp[i][j] = max(dp[i-1][j], dp[i][j-1])


// MLE 

// hint? 

// Consider the first K stock prices. 
// At the end, the only legal states are that you don't own a share of stock, 
// or that you do. Calculate the most profit you could have under each of these two cases.


// define the problem: dp[i][j]
// i means prices[::i]
// j means own a stock or not

// dp size n*2

// profit = max(dp(i-1, 0), dp(i-1, 1) + prices[i] - fee)
// dp[i][0] = profit
// dp[i][1] = profit - prices[i];

// base case
// dp[0][0] = 0
// dp[0][1] = 0 - prices[0];

// [1, 3, 2, 8, 4, 9]
//  b        s  b  s
//  0  0  0  
// -1 -3 -2