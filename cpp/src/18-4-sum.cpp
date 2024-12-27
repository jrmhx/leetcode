/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end(), std::less<int>());
        for (int j = 0; j < nums.size() - 3; j++){
            if ((j>0 && nums[j] == nums[j-1] )|| (nums[j] >= 0 && target < 0)) {
                continue;
            }
            long long t = target - nums[j];
            for (int i = j+1; i < nums.size() - 2; i++){
                if ((i>j+1 && nums[i] == nums[i-1]) || (nums[i] >= 0 && t < 0)) {
                    continue;
                }
                long long tt = t - nums[i];
                int left = i+1, right = nums.size() - 1;
                while (left < right){
                    if (nums[left] + nums[right] < tt){
                        left++;
                    } else if (nums[left] + nums[right] > tt){
                        right--;
                    } else {
                        ans.emplace_back(vector<int>{nums[j], nums[i], nums[left], nums[right]});
                        do{
                            left++;
                        } while (left < nums.size() - 1 && nums[left] == nums[left-1]);
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

