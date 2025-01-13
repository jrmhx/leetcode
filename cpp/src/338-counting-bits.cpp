/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> btc;

        for (int i = 0; i<=n; i++){
            int sum = 0;
            int m = i;

            while (m) {
                int lowbit = m & -m;
                sum++;
                m -= lowbit;
            }

            btc.push_back(sum);
        }

        return btc;
    }
};
// @lc code=end

