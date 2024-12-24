/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

		vector<int> result;

		for (int i = 0; i < nums.size(); i++){
			if (umap.find(target - nums[i]) == umap.end()){
				umap[nums[i]] = i;
			} else {
				result.push_back(umap[target-nums[i]]);
				result.push_back(i);
				break;
			}
		}

		return result;
    }
};
// @lc code=end

