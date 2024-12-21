/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto left = nums.begin();
		auto right = k <= nums.size() ? nums.begin() + k : nums.end();
		int max = accumulate(left, right, 0);

		int currMax = max;

		while (right != nums.end()){
			currMax += *right - *left;
			max = max < currMax ? currMax : max;
			right++;
			left++;
		}

		return static_cast<double>(max) / k;
    }
};
// @lc code=end

int main(){
	Solution s;
	vector<int> nums = {1,12,-5,-6,50,3};
	int k = 4;
	auto res = s.findMaxAverage(nums, k);
	std::cout << res << std::endl;
	return 0;
}