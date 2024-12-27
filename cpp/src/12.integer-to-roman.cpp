/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman_map = {
			{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"},
			{10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"},
			{100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"},
			{1000, "M"}
		};

		string roman = "";
		while (num){
			auto it = roman_map.upper_bound(num);
			if(it == roman_map.begin()){ // no element is <= nums (should be illegal)
				return "??????";
			} else {
				it--;
				roman += (*it).second;
				num -= (*it).first;
			}
		}
		return roman;
    }
};
// @lc code=end

