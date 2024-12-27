/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
		unordered_set<string> wset(words.begin(), words.end());
		int wlen = words[0].length();

		for (int i = 0; i < wlen; i++){
			unordered_multiset<string> wmset(words.begin(), words.end());
			sliding(i, s, words, ans, wmset, wset);
		}
		
		return ans;
    }

	private:
	int moveptr (int src, int fwd, int wlen, const string s, unordered_multiset<string> &wmset, const unordered_set<string> &wset){
		// fwd should be m*wlen
		if (wlen * (fwd / wlen) != fwd){
			throw("!!!!!!! fwd should be m * wlen !!!!!!");
		}
		string currw = "";
		while (fwd > 0){
			if (src >= s.length()) return src;
			currw = s.substr(src, wlen);
			const auto it = wset.find(currw);

			if (it != wset.end()){ // the currw is in words
				wmset.insert(currw);
			}
			src += wlen;
			fwd -= wlen;
		}

		return src;
	}

	void sliding(int i, const string &s, const vector<string> &words, vector<int> & ans, unordered_multiset<string> &wmset, const unordered_set<string> &wset){
		int left = i, right = left;
		int wlen = words[0].length();
		
		string currw = "";

		for (; right + wlen <= s.length(); right += wlen){
			currw = s.substr(right, wlen);
			const auto it = wset.find(currw);
			auto mit = wmset.find(currw);

			if (it == wset.end()){ // the currw is not in words
				// left => right + wlen;
				left = moveptr(left, right - left + wlen, wlen, s, wmset, wset);
			} else if (mit == wmset.end()){ // currw in words but is reused now
				// left => right;
				while(wmset.find(currw) == wmset.end()){
					left = moveptr(left, wlen, wlen, s, wmset, wset);
				}
				mit = wmset.find(currw); // CAREFUL for nullptr
				if (mit != wmset.end()) {
					wmset.erase(mit);
				}
			} else if (mit != wmset.end()) {
				wmset.erase(mit);
			}

			if (wmset.size() == 0){ // a con str find!
				ans.push_back(left);
				left = moveptr(left, wlen, wlen, s, wmset, wset);
			}
		}
	}
};
// @lc code=end

int main(){

	Solution sol;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = {"word","good","best","word"};

	auto ans = sol.findSubstring(s, words);
	
	for_each(ans.begin(), ans.end(), [](int i){cout << i << " ";});
	return 0;
}

// concatenated str: 
// 	1. a continous sub str
//	2. has to contain EXACTLLY a centain permutation in words

// window break situations (left need += wlen):
// 1. confliction with con str
// 2. finished a con str

// if it not in wset (currw not in words): left -> right + wlen
// if it in wset but mit not in wmset: left -> right
// if wmset.size() == 0 (find a con str): ans.push_back(left), left -> left + wlen

// abdcab ab cd 
// l

// 
// wordgoodgoodgoodbestword
// l   l
// r   r   r   r   
// ["word","good","best","good"]