/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
		// sliding window
        int k = 1, left = 0, right = 0, curr = 0, ans = 0;

		for (; right < nums.size(); right++){
			// logic to add nums[right] into window 

			if(nums[right] == 0) {
                k--;
            } else {
                curr++;
            }

			while(k < 0){ // window condition broken
				// remove nums[left] from window logic
				k += 1-nums[left];
				if (nums[left]==1) curr--;
				left++;
			}
			if (curr - k > ans) ans = curr - k;
			// udpate ans
		}

		return ans;
    }
};
// @lc code=end

// reture size