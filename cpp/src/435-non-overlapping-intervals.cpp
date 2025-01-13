/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int kicked = 0;

        int start = intervals[0][0];

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++){
            auto * newInterval = &intervals[i];
            int nstart = (*newInterval)[0];
            int nend = (*newInterval)[1];

            if(nstart >= end){
                // no overlap:
                end = nend;
            } else {
                kicked++;
                end = std::min(end, nend);
            }
        }

        return kicked;
    }
};
// @lc code=end

