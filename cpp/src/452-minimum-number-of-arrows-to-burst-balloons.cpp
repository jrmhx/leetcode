/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());

        int arrow = 1;
        vector<int> arrowInterval = points[0];

        for (int i = 1; i < points.size(); i++){
            int start = points[i][0];
            int end = points[i][1];

            if (arrowInterval[0] <= start && arrowInterval[1] >= end) { // if arrowInterval totally contains in coming ballon
                arrowInterval[0] = start;
                arrowInterval[1] = end;
            }

            if (start > arrowInterval[1]){ // no overlap case
                arrow++;
                arrowInterval[0] = start;
                arrowInterval[1] = end;
            }

            if (start <= arrowInterval[1] && end > arrowInterval[1] ){ // partially overlapd
                arrowInterval[0] = start;
            }
        }

        return arrow;
    }
};
// @lc code=end

// [[9,12],[8,12]]
