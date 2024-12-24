/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <string>
#include <set>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
		unordered_map<char, int> tmap;
		for(const auto & c : t) tmap[c]++;
        multiset<char> ts(t.begin(), t.end());

		pair<int, int> slice(-1,-1);

		int left=0, right=0;
		
		for (; right < s.length(); right++){
			const auto it = ts.find(s[right]);
			if (it != ts.end()) {
				ts.erase(it);
			}

			tmap[s[right]]--;

			while(ts.size() == 0 ){ // we got all the chars in t
				// time to shrink window to meet "minimum"
				if (tmap.find(s[left]) != tmap.end()) {
					tmap[s[left]]++;
					if (tmap[s[left]] > 0) ts.insert(s[left]);
					if (slice.first!=-1){
						if (right - left < slice.second - slice.first){
							slice.first = left;
							slice.second = right;
						}
					} else {
						slice.first = left;
						slice.second = right;
					}
				}
				left++;
			}
		}

		return (slice.first != -1) ? s.substr(slice.first, slice.second - slice.first + 1) : "";
    }
};
// @lc code=end

// s: XXXXAXXXBXXXCXXXDXXX

// t: ABCD