/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
		int curr = 0;

		for_each(gain.begin(), gain.end(), [&max, &curr](const auto & a){
			curr += a;
			max = curr > max ? curr : max;
		});
		return max;
    }
};
// @lc code=end

