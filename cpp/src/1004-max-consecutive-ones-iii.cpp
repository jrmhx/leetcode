/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, curr = 0, ans = 0, flip = k;

		for (int right = 0; right < nums.size(); right++){
			// logic for add nums[right] in to window
			if(nums[right] == 0) flip--;

			while (/*window_condition_break*/  flip < 0){
				// remove left for the window
				flip += 1 - nums[left];
				left++;
			}

			//update ans

			curr = right-left+1;
			ans = curr > ans ? curr : ans;
		}

		return ans;
	}
};
// @lc code=end


// left: ancher
// right: expand win size
// flip: # that we can do flip left for a current left ptr win

// 1 1 1 0 0 0 1 1 1 1 0 k=2
// 1 1 1 1 0 0 0 0 0 k=1 right=9