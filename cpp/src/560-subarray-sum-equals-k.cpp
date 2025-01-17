/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> lkupTable;
        lkupTable[0] = 1;

        int ans = 0, sum = 0, lkup;

        for (auto num : nums){
            sum += num;

            // k = sum - lkup;
            lkup = sum - k;

            if (lkupTable.find(lkup) != lkupTable.end()){
                ans += lkupTable[lkup];
            }

            if (lkupTable.find(sum) != lkupTable.end()) {
                lkupTable[sum]++;
            } else {
                lkupTable[sum] = 1;
            }
        }

        return ans;
    }
};
// @lc code=end

