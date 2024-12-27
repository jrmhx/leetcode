/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
		int sum = 0;
        vector<int> lsum;
		vector<int> rsum;

		for_each(nums.begin(), nums.end(), [&sum, &lsum](int a){
			sum+=a;
			lsum.push_back(sum);
		});

		for_each(nums.begin(), nums.end(), [&sum, &rsum](int a){
			sum-=a;
			rsum.push_back(sum);
		});

		if(rsum[0] == 0) return 0;

		for(int i = 0; i < nums.size()-1; i++){
			if (lsum[i] == rsum[i+1]) return i + 1;
		}

		return -1;
    }
};
// @lc code=end

// lsum[i] sum of nums[::i]
// rsum[i] sum of nums[i::]
// [2, 1, -1]
// [0, -1, 1]

// 1 -1 2
// 1, 0, 2
// 1, 2, 0

// [1, 7, 3, 6, 5, 6]
// [1, 8, 11, 17, 22, 28]
// [27, 20, 17, 11, 6, 5]

// lsum[i] == rsum[i+1] ?