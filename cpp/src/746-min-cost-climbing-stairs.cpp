/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cs = {0};
		for (int c : cost) cs.push_back(c);
		unordered_map<int, int> map;
		return dp(0, cs, map);
    }

	int dp(int i, vector<int> &cost, unordered_map<int, int> &map){
		if (cost.size() - i <= 2){
			return cost[i];
		} else {
			if (map.find(i) != map.end()){
				return map[i];
			} else {
				int curr = cost[i] + min(
					dp(i+1, cost, map),
					dp(i+2, cost, map)
				);
				map[i] = curr;
				return curr;
			}
		}
	}
};
// @lc code=end

// 0, 10, 15, 20
// 0, 1,   2, 3

// minCCS(i) = cost[i] + min(minCCS(cost[i+1::]), minCCS(cost[i+2::]))

