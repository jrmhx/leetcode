/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxRob(nums.size()+2, 0);

		for (int i = nums.size() - 1; i >= 0; i--) 
			maxRob[i] = max((nums[i] + maxRob[i+2]), maxRob[i+1]);
		
		return maxRob[0];
    }
};
// @lc code=end

// n = 4
//  idx:   0, 1, 2, 3, 
// nums:   1, 2, 3, 1, 0, 0
// maxRob: 4, 3, 3, 1, 0, 0 means: the max money can be robbed from nums[i::]  [i, nums.size())
// maxRob[i] = max((nums[i] + maxRob[i+2]), maxRob[i+1])

// Time Comp:
//
// maxRob[i] = max((nums[i] + maxRob[i+2]), maxRob[i+1])
//
// the i range: [0, nums.size())  O(n)
// for each i there's a recurrence relations -> O(n)
// for each recurrence relation, the cached time complexity O(1)
// Total TC: O(n) 

// 3 2 2 1 2 5
// 0 1 2 3 4 5 6 7 8 9 10 .... 1000
// 0 2 4
// 5
// 