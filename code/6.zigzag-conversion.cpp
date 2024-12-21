/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> grid;

		for (int i = 0; i < s.length(); i++){
			
		}
    }
};
// @lc code=end

// PAYPAL
//str: 123456789
//str: 123212321
//dir:+  - + -  
// dir {1,-1} x,y
// when dir is +1 -> next char pos: {x, y} -> {x, y++}
// when dir is -1 -> next char pos: {x, y} -> {x+1, y-1}

