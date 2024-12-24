/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        // int [] arr
		// arr[i] means the # of vowel letter in s[0:i] (not included i)
		// asdfafs
		// 01111222

		// sliding window
		// k = 3
		// s[0, 1, 2]
		// #v s[x:y+1] = #v s[0:y+1] - #v s[0: x]     ({s[x], .... ,s[y]})
		// 				arr[x+k] - arr[x]
		vector<int> nvsub = {0};
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		int nv = 0;

		for (const auto c : s){
			if (vowels.find(c) != vowels.end()){
				nv++;
			}
			nvsub.push_back(nv);
		}
		int res = 0;
		for (int i = 0; i + k < nvsub.size(); i++){
			int temp = nvsub[i+k] - nvsub[i];
			if (temp > res) res = temp;
		}

		return res;
    }
};
// @lc code=end

