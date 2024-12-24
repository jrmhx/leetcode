/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};

		int result = 0;
		int temp = 0;
		int sign = 1;

		for (char c : s){
			if (c == 'V' || c == 'X') {
				sign = temp == 1 ? -1 : 1;
			}
			if (c == 'L' || c == 'C') {
				sign = temp == 10 ? -1 : 1;
			}
			if (c == 'D' || c == 'M') {
				sign = temp == 100 ? -1 : 1;
			}
			result += sign*temp;
			temp = umap[c];
			sign = 1;
		}
		result += sign*temp;
		return result;
    }
};
// @lc code=end

// if c is one of C M I V 
//       0   -100   900  899  904
