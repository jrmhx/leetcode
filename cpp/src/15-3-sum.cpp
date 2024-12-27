/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
        
		sort(nums.begin(), nums.end(), std::less<int>());

		for (int i = 0; i < nums.size() - 2; i++){
			if (i>0 && nums[i] == nums[i-1]) {
				continue;
			}
			int target = (-1) * nums[i];
			int left = i+1, right = nums.size() - 1;
			while (left < right){
				if (nums[left] + nums[right] < target){
					left++;
				} else if (nums[left] + nums[right] > target){
					right--;
				} else {
					ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
					do{
						left++;
					} while (left < nums.size() - 1 && nums[left] == nums[left-1]);
				}
			}
		}

		return ans;
    }
};
// @lc code=end

// 0 1 2 -2 -1


