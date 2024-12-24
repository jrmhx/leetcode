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
		if (numRows == 1 || numRows >= s.length()) return s;
        vector<vector<char>> rows(numRows);
		int offset = 1; // init direction
		int r = 0; // init row to start with
		for(char c : s){
			if (r == 0) offset = 1;
			if (r == numRows - 1) offset = -1;
			rows[r].push_back(c);
			r += offset;
		}
		string result = "";
		for (const auto & row : rows){
			for (char c : row){
				result += c;
			}
		}
		return result;
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

