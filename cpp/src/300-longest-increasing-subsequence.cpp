/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <vector>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n + 10, 0);
        lis[0] = 1;
        int ans = 1;

        for (int i = 1; i < n; i++){
            int num = nums[i];
            int maxSqLen = 0;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]) { 
                    // nums[j] can accept nums[i] as its next node in a strictly increasing subseq
                    maxSqLen = max(lis[j], maxSqLen);
                }
            }
            lis[i] = maxSqLen+1;
            ans = max(ans, lis[i]);
        }

        return ans;
    }
};
// @lc code=end

// define the problem: lis(i) means the max length of LIS for node nums[i]

// recurrence relation
// lis(i) = max length lis(j)+1, where j<i && nums[j] can accept nums[i]

// optm 
// where: the lookup process for nums[j] that can accept nums[i]
// hint O(N*log(N)) -> tree/map/binary search

// map<int, int> key: nums[i] val: i
// for each nums[i]
//   we put nums[i] into map
//   map.find(nums[i]) != map.begin() | end() -> the j we looking is it-1;

// 0   1  2  3  4  5   6    7
// 10, 9, 2, 5, 3, 7, 101, 18
// 1   1  1  2  2  3  2   2
// -   -  -  2  2  
