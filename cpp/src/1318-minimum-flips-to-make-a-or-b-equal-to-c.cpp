/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ((a | b) ^ c));
    }
};
// @lc code=end

// a OR b == c 

// let say c[i] means ith bit in c
// if c[i] == 1 
// flip++ iff a[i] and b[i] all 0

// if c[i] == 0
// a[i] and b[i] must be 0