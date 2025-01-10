/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
		unordered_map<pair<int, int>, int> umap;

		auto combo = [&](int i, int m, int c) -> unsigned int {
			if (i == coins.size()) {
				if (m > 0) return -1;
			}
			if (m == 0) {
				return c;
			}
		};
    }
};
// @lc code=end
int main(){

	return 0;
}
// DFS
// 
// 

