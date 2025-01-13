/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (auto num: nums){
            ans ^= num;
        }

        return ans;
    }
};
// @lc code=end

// 1 0 0 1 XOR
// 1 0 1 0
// 0 0 1 1

// a ^ b ^ c == (a ^ c) ^ b
