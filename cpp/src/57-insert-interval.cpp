/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto cmp = [](const vector<int> & a, const vector<int> & b){
			return a[0] < b[0];
		};

		auto lb = lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);
		intervals.insert(lb, newInterval);
		// Merge overlapping intervals
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            // If res is empty or there is no overlap, add the interval to the
            // result
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
                // If there is an overlap, merge the intervals by updating the
                // end of the last interval in res
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
		return ans;
    }
};
// @lc code=end
