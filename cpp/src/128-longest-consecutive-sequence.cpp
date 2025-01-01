/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
		unordered_map<int, int> map;

		for (int num : nums){
		}

		return max;
    }
};
// @lc code=end

// 100 4 1 3 2 2 99 101  {4}
// max = max(max, curr)
// 3 2 4 1
// 2 3 4 1 5 0
// 

// update condition: map.find(val) == map.end() || map[val] == 0

// update: map[i] += map[i-1] + map[i+1] + 1 (element)

// map[nums[i]] meaning: current the longest length of consecutive elements series that contains i
